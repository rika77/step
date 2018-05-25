#include <cmath>
#include <iostream>
using namespace std;

int MysteryFunction(string str) {
    int ans = 0;
	int n = str.size() - 1;
    for (int i = n; i >= 0; --i) {
        if (str[i] == '1') {
            ans += pow(2, n-i);  // 処理 A
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
