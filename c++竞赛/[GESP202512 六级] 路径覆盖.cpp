#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
vector<int> g[N];
int n,f[N];
ll c[N],dp[N];
void solve(int u,int fa){
	dp[u]=c[u];
	ll cnt=0;
	for(auto d:g[u]){
		if(d==fa) continue;
		solve(d,u);
		cnt+=dp[d];
	}
	if(g[u].size()>=2) dp[u]=min(dp[u],cnt);
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	for(int i=2;i<=n;i++) cin>>f[i];
	for(int i=1;i<=n;i++){
		g[f[i]].push_back(i);
		g[i].push_back(f[i]);
	}
	for(int i=1;i<=n;i++) cin>>c[i];
	solve(1,0);
	cout<<dp[1];
	return 0;
}

