#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
const int N=2e3+10;
int n,k,sum[N];
ll dp[N][N];
vector<pair<int,int>> g[N];
void dfs(int cur,int fa){
	sum[cur]=1;
	for(auto d:g[cur]){
		if(d.fi==fa) continue;
		else dfs(d.fi,cur);
		sum[cur]+=sum[d.fi];
		for(int i=max(k,sum[i]);i>=0;i--){
			for(int j=max(i-sum[cur]+sum[d.fi],0);j<=min(i,sum[d.fi]);j++){
				dp[cur][i]=max(dp[cur][i],dp[cur][i-j]+dp[d.fi][j]+1ll*j*(k-j)*d.se+1ll*(sum[d.fi]-j)*(n-k-sum[d.fi]+j)*d.se);
			}
		}
	}
	return;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>k;
	for(int i=1;i<n;i++){
		ll u,v,w;
		cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	k=min(k,n-k);
	dfs(1,0);
	cout<<dp[1][k];
	return 0;
}

