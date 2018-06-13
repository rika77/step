def readNumber(line, index):
    number = 0
    flag = 0
    keta = 1
    while index < len(line) and (line[index].isdigit() or line[index] == '.'):
        if line[index] == '.':
            flag = 1
        else:
            number = number * 10 + int(line[index])
            if flag == 1:
                keta *= 0.1
        index += 1
    token = {'type': 'NUMBER', 'number': number * keta}
    return token, index


def readPlus(line, index):
    token = {'type': 'PLUS'}
    return token, index + 1


def readMinus(line, index):
    token = {'type': 'MINUS'}
    return token, index + 1

def readMul(line, index):
    token = {'type': 'MUL'}
    return token, index + 1

def readDiv(line, index):
    token = {'type': 'DIV'}
    return token, index + 1

def readL(line, index):
    token = {'type': 'LPARLEN'}
    return token, index + 1

def readR(line, index):
    token = {'type': 'RPARLEN'}
    return token, index + 1


def tokenize(line):
    tokens = []
    index = 0
    while index < len(line):
        if line[index].isdigit():
            (token, index) = readNumber(line, index)
        elif line[index] == '+':
            (token, index) = readPlus(line, index)
        elif line[index] == '-':
            (token, index) = readMinus(line, index)
        elif line[index] == '*':
            (token, index) = readMul(line, index)
        elif line[index] == '/':
            (token, index) = readDiv(line, index)
        elif line[index] == '(':
            (token, index) = readL(line, index)
        elif line[index] == ')':
            (token, index) = readR(line, index)
        else:
            print 'Invalid character found: ' + line[index]
            exit(1)
        tokens.append(token)
    return tokens

def evaluate_parlen(tokens):
    index = 0
    l_num = r_num = 0
    left_end = 0
    while index < len(tokens):
        if tokens[index]['type'] == 'LPARLEN':
            # memorize "left end"
            if l_num == 0:
                left_end = index
            l_num += 1
        elif tokens[index]['type'] == 'RPARLEN':
            r_num += 1
        # Find a Pair !
        if l_num == r_num and l_num != 0:
            # Take out inner ()
            answer = tokens[left_end + 1:index]
            # (~~) print l_num, r_num, index
            num = evaluate(answer)
            del tokens[left_end:index + 1]
            tokens.insert(left_end, {'type': 'NUMBER', 'number': num})
            l_num = r_num = 0
            index = left_end
        index += 1
    return tokens

def evaluate_mul_div(tokens):
    # *, /
    index = 0
    while index < len(tokens):
        if tokens[index]['type'] == 'MUL':
            # a mul b -> c (substitute)
            num = tokens[index - 1]['number'] * tokens[index + 1]['number']
            del tokens[index - 1 : index + 2]
            tokens.insert(index - 1, {'type': 'NUMBER', 'number': num})
        elif tokens[index]['type'] == 'DIV':
            # a mul b -> c (substitute)
            # tips: '*1.0' -> Allow decimal 
            num = tokens[index - 1]['number'] * 1.0 / tokens[index + 1]['number']
            del tokens[index - 1 : index + 2]
            tokens.insert(index - 1, {'type': 'NUMBER', 'number': num})
        else:
            index += 1
    return tokens

def evaluate_pl_mi(tokens):
    # +, -
    answer = 0
    tokens.insert(0, {'type': 'PLUS'}) # Insert a dummy '+' token
    index = 1
    while index < len(tokens):
        if tokens[index]['type'] == 'NUMBER':
            if tokens[index - 1]['type'] == 'PLUS':
                answer += tokens[index]['number']
            elif tokens[index - 1]['type'] == 'MINUS':
                answer -= tokens[index]['number']
            else:
                print 'Invalid syntax'
        index += 1
    return answer

def evaluate(tokens):
    tokens = evaluate_parlen(tokens)
    tokens = evaluate_mul_div(tokens)
    answer = evaluate_pl_mi(tokens)
    return answer



def test(line, expectedAnswer):
    tokens = tokenize(line)
    actualAnswer = evaluate(tokens)
    # actualAnswer = evaluate_pl_mi(evaluate_mul_div(evaluate_parlen(tokens)))
    if abs(actualAnswer - expectedAnswer) < 1e-8:
        print "PASS! (%s = %f)" % (line, expectedAnswer)
    else:
        print "FAIL! (%s should be %f but was %f)" % (line, expectedAnswer, actualAnswer)


# Add more tests to this function :)
def runTest():
    print "==== Test started! ===="
    test("1+2", 3)
    test("1.0+2.1-3", 0.1)
    test("5/2*3.0", 7.5)
    test("((1+2)+3)+4", 10)
    test("1+(2+(3+4))", 10)
    test("(1+1)+(1+1)", 4)
    test("(1+2)*3", 9)
    test("(3.0+4*(2-1))/5", 1.4)
    print "==== Test finished! ====\n"

runTest()

while True:
    print '> ',
    line = raw_input()
    tokens = tokenize(line)
    answer = evaluate(tokens)
    print "answer = %f\n" % answer
