#include <iostream>
#include <string>
#include <vector>
using namespace std;

string unknownFunction(vector<string> strs) {
  int x = 0;
  string y;
  for (int i = 0; i < strs.size(); i++) {
	  //各単語について
    string str = strs[i];
    if (str.size() > x) {
		//初めて出てきた最大長のやつ
      x = str.size();
      cout << "hoge" << endl;
	  y = str;
    }
  }
  return y;
}

int main() {
  vector<string> strs = {
    "dog", "cat", "lion", "tiger", "horse"
  };
  cout << unknownFunction(strs) << endl;
  return 0;
}
