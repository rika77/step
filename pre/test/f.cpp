#include <cmath>
#include <iostream>
using namespace std;

int MysteryFunction(string str) {
    int ans = 0;
    for (int i = str.size() - 1; i >= 0; --i) {
        if (str[i] == '1') {
            ans += pow(2, i);  // 処理 A
        }
    }
    return ans;
}

int main() {
	string a;
	cin >> a;
    cout << MysteryFunction(a) << endl;
    return 0;
}
