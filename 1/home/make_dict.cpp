#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) FOR(i,0,n)
typedef long long ll;
typedef pair<string,string> P;

int main(){
	vector<P> dict;
	string word;
	while(cin >> word){
		string word2 = word;
		sort(word.begin(), word.end());
		dict.push_back(P(word, word2));
		cout << word << endl;
		cout << word2 << endl;
	}
	return 0;
}

