#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10;
int m,n,nxt[N];
string s,t; 
void getnxt(){
	nxt[1]=0;
	for(int i=2,j=0;i<=n;i++){
		while(j&&t[i]!=t[j+1]) j=nxt[j];
		if(t[i]==t[j+1]) j++;
		nxt[i]=j;
	}
}
void kmp(){
	for(int i=1,j=0;i<=m;i++){
		while(j&&s[i]!=t[j+1]) j=nxt[j];
		if(s[i]==t[j+1]) j++;
		if(j==n) cout<<i-j+1<<"\n";
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>s>>t;
	m=s.size();n=t.size();
	s=' '+s;t=' '+t;
	getnxt();
	kmp();
	for(int i=1;i<=n;i++) cout<<nxt[i]<<" ";
	return 0;
}
