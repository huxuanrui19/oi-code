#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100+10;
int dp[N][N]; 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	memset(dp,0x3f,sizeof(dp));
	int n,m;
	cin>>n>>m;
    for(int i=1;i<=n;i++) dp[i][i]=0;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		dp[u][v]=dp[v][u]=min(dp[u][v],w);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				dp[j][k]=min(dp[j][k],dp[j][i]+dp[i][k]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<"\n";
	}
	return 0;
}

