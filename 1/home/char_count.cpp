#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) FOR(i,0,n)
typedef long long ll;
int main(){
	string a;
	cin >> a;
	int len = a.size();
	map<char,int> count;
	rep(i,len){
		//文字数のカウントにはhashかな。
		++count[a[i]];
	}

	for (auto &item: count) {
		cout << item.first << " " << item.second << endl;
	}

	return 0;
}
