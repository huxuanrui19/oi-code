#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100+10;
const ll inf=1e13;
ll g[N][N],dis[N][N],dp[N][N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j) dp[i][j]=dis[i][j]=inf;
		}
	}
	for(int i=1;i<=m;i++){
		ll u,v,w;
		cin>>u>>v>>w;
		dp[u][v]=min(dp[u][v],w);
		dp[v][u]=min(dp[v][u],w);
		dis[v][u]=min(dis[v][u],w);
		dis[u][v]=min(dis[u][v],w);
	}
	ll ans=inf;
	for(int k=1;k<=n;k++){
		for(int i=1;i<=k-1;i++){
			for(int j=i+1;j<=k-1;j++){
				ans=min(ans,dis[i][j]+dp[j][k]+dp[k][i]);
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	if(ans==inf) cout<<"No solution.";
	else cout<<ans;
	return 0;
}

