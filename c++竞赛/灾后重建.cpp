#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200+10;
int t[N],g[N][N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>t[i];
	}
	memset(g,0x3f,sizeof(g));
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		g[v][u]=g[u][v]=w;
	}
	int q,cnt=-1,last=-1;
	cin>>q;
	while(q--){
		int x,y,ti;
		cin>>x>>y>>ti;
		cnt=upper_bound(t,t+n,ti)-t-1;
		for(int k=last+1;k<=cnt;k++){
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
				}
			}
		}
		last=cnt;
		if(g[x][y]==0x3f3f3f3f||x>cnt||y>cnt) cout<<"-1\n";
		else cout<<g[x][y]<<"\n";
	}
	return 0;
}

