#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10;
int cnt=0,trie[N][26],ok[N][26];
int judge(char c){
	return c-'a';
}
void build(string s){
	int now=0;
	for(int i=0;i<s.size();i++){
		int id=judge(s[i]);
		if(trie[now][id]==0) trie[now][id]=++cnt;
		if(i==s.size()-1) ok[now][id]++;
		now=trie[now][id];
	}
}
int ask(string s){
	int now=0,ans=0;
	for(int i=0;i<s.size();i++){
		int id=judge(s[i]);
		if(trie[now][id]==0) return ans;
		ans+=ok[now][id];
		now=trie[now][id];
	}
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		string s;
		cin>>s;
		build(s);
	}
	for(int i=1;i<=m;i++){
		string s;
		cin>>s;
		cout<<ask(s)<<endl;
	}
	return 0;
}

