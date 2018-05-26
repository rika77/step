#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) FOR(i,0,n)
typedef long long ll;

int main(){
	//ファイルから読み込み
	map<string, string> dict;

	ifstream ifs("dict_order.txt");
	if(ifs.fail()){
		cerr << "failed" << endl;
		return -1;
	}
	string str1, str2;
	while(getline(ifs, str1)){
		getline(ifs, str2);
		dict[str1] = str2;	//(aelpp, apple)
	}

	string a;
	cin >> a;
	sort(a.begin(), a.end());

	if (dict[a].size()!=0) {
		cout << dict[a] << endl;
	}
	else {
		cout << "NOT FOUND" << endl;
	}
	
	return 0;
}

