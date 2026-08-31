#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3e6+10;
int cnt=0,tree[N][63],tot[N];
int judge(char c){
	if(c>='a'&&c<='z') return int(c-'a');
	if(c>='A'&&c<='Z') return int(c-'A'+26);
	return int(c-'0'+52);
}
void insert(char *s){
	int p=0;
	for(int i=0;i<strlen(s);i++){
		int idx=judge(s[i]);
		if(tree[p][idx]) p=tree[p][idx];
		else tree[p][idx]=++cnt,p=cnt;
		tot[p]++;
	}
}
int ask(char *t){
	int p=0;
	for(int i=0;i<strlen(t);i++){
		int idx=judge(t[i]);
		if(tree[p][idx]==0) return 0;
		p=tree[p][idx];
	}
	return tot[p];
}
char s1[N];
int main() {
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	int t;cin>>t;
	while(t--){
		int n,q;
		cin>>n>>q;
		for(int i=0;i<=cnt;i++){
			tot[i]=0;
			for(int j=0;j<63;j++) tree[i][j]=0;
		}
        cnt=0;
		for(int i=1;i<=n;i++){
			cin>>s1;
			insert(s1);
		}
		for(int i=1;i<=q;i++){
			cin>>s1;
			cout<<ask(s1)<<"\n";
		}
	}
	return 0;
}

