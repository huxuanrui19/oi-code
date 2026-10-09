#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e3+10;
vector<pair<int,ll> >g[N];
ll md,dp[N];
void init(){
	for(int i=1;i<N;i++) dp[i]=0;
	md=0;
}
void dfs(int u,int fa){
	ll ma=0,se=0;
	for(auto d:g[u]){
		int v=d.first;
		ll w=d.second;
		if(v==fa) continue;
		dfs(v,u);
		se=max(se,dp[v]+w);
		if(se>=ma) swap(se,ma);
		md=max(md,se+ma);
	}
	dp[u]=ma;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	for(int i=1;i<n;i++){
		int u,v;
		ll w;
		cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	
	ll ans=1e14;
	for(int u=1;u<=n;u++){
		for(auto d:g[u]){
			init();
			int v=d.first;
			ll w=d.second,d1,d2;
			dfs(u,v);d1=md;md=0;
			dfs(v,u);d2=md;md=0;
			ans=min(ans,max({d1,d2,}));
		}
	}
	cout<<ans;
	return 0;
}

