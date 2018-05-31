#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) FOR(i,0,n)
typedef long long ll;

// 改行いりで入力される文字を、一列に出力する
//まずは一回で...

int main(){
	string a;
	string ans="";
	while(cin >> a){
		if (a == "Qu"){
			a = "QU";
		}
		ans += a;
	}
	cout << ans << endl;
	return 0;
}
