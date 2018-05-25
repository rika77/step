#include <cmath>
#include <iostream>
using namespace std;

int MysteryFunction2(string str) {
  int ans = 0;
  for (int i = 0; i < str.size(); ++i) {
    char c = str[i];
    ans *= 2;
    if (c == '1') {
      ans += 1;
    }
  }
  return ans;
}

int main() {
	string a;
	cin >> a;
    cout << MysteryFunction2(a) << endl;
    return 0;
}
