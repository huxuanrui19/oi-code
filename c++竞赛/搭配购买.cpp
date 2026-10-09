#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e4+10;
int cnt=0,fa[N],c[N],d[N],dp[2][N],cc[N],dd[N],dui[N];
int fi(int s){
	if(s!=fa[s]) return fa[s]=fi(fa[s]);
	return s;
}
void mer(int x,int y){
	x=fi(x);
	y=fi(y);
	if(x!=y) fa[x]=y; 
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,m,w;
	cin>>n>>m>>w;
	for(int i=1;i<=n;i++){
		fa[i]=i;
		cin>>c[i]>>d[i];
	}
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		mer(u,v);
	}
	for(int i=1;i<=n;i++){
		if(!dui[fi(i)]){
			dui[fi(i)]=++cnt;
		}
		cc[dui[fi(i)]]+=c[i];
		dd[dui[fi(i)]]+=d[i];
	}
	for(int i=1;i<=cnt;i++){
		for(int j=1;j<=w;j++){
			dp[i%2][j]=dp[(i+1)%2][j];
			if(j>=cc[i]) dp[i%2][j]=max(dp[i%2][j],dp[(i+1)%2][j-cc[i]]+dd[i]);
		}
	}
	cout<<dp[cnt%2][w];
	return 0;
}

