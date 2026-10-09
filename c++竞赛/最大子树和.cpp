#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
ll dp[N],a[N];
vector<int> g[N]; 
void dfs(int u,int fa){
	dp[u]=a[u];
	for(auto d:g[u]){
		if(d==fa) continue;
		dfs(d,u);
		dp[u]+=max(dp[d],0ll);
	}
	return;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1,0);
	ll ans=-1e16;
	for(int i=1;i<=n;i++){
		ans=max(ans,dp[i]);
	}
	cout<<ans;
	return 0;
}

