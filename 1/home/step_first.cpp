#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) FOR(i,0,n)
typedef long long ll;
typedef pair<int, string> P;
int main(){
	//ファイルから読み込み
	map<string, string> dict;

	ifstream ifs("dict_order.txt");
	if(ifs.fail()){
		cerr << "failed" << endl;
		return -1;
	}
	string fi, se;
	while(getline(ifs, fi)){
		getline(ifs, se);
		dict[fi] = se;	//(aelpp, apple)
	}

	string str2;
	cin >> str2;
	sort(str2.begin(), str2.end());
/*
	if (dict[a].size()!=0) {
		cout << dict[a] << endl;
	}
	else {
		cout << "NOT FOUND" << endl;
	}
*/

	//部分文字列ならok!
	vector<P> ans;
	vector<char> three{'j','k','q','x','z','J','K','Q','X','Z'};
	vector<char> two{'c','f','h','l','m','p','v','w','y','C','F','H','L','M','P','V','W','Y'};
	for (auto &item: dict) {
		string str1 = item.first;
		int i=0;
		int len1 = str1.size();
		int len2 = str2.size();	//16で決め打ちしてもよい？qu？
		rep(j,len2){
			if (str1[i]==str2[j]){
				i++;
			}
		}
		//問題点:quじゃなくて、uしか入ってないやつも...手動で排除？
		if(i==len1){
			//正解なら、点数をつけてansに入れる(あとでsortする)
			int po = 0;
			rep(k,len1){
				if (find(three.begin(), three.end(), str1[k])!=three.end()){				
					po += 3;
				}
				else if (find(two.begin(), two.end(), str1[k])!=two.end()){	
					po += 2;
				}
				else{
					po += 1;
				}
			}
			ans.push_back(P(po, str1));
		}
	}

	sort(ans.begin(), ans.end());
	int len = ans.size();
	rep(k,len){
		cout << ans[k].first << " " <<  dict[ans[k].second]<<endl;
	}

		
	return 0;
}

