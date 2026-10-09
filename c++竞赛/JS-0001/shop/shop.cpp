#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=40;
ll n,m,c[N],w[N],ans[N];
ll sta=0;
vector<int> g[N];
void dfs(int u,ll num){
	int flag=0;
	if((sta&(1<<(c[u]-1)))==0) num+=w[c[u]],sta=sta|(1<<(c[u]-1)),flag=1;
	ans[u]=max(ans[u],num);
	for(auto d:g[u]){
		dfs(d,num);
	}
	if(flag==1) sta^=(1<<(c[u]-1));
}
ll deg[N],dp[N][(1<<20)+10];
void topo(){
	dp[1][(1<<(c[1]-1))]=w[c[1]];
	queue<int> q;q.push(1);
	for(int i=1;i<=n;i++){
		for(auto d:g[i]) deg[d]++;
	}
	while(!q.empty()){
		int u=q.front();q.pop();
		for(auto d:g[u]){
			for(int i=0;i<(1<<20);i++){
				dp[d][i|(1<<(c[d]-1))]=max(dp[d][i|(1<<(c[d]-1))],dp[u][i]+((i&(1<<(c[d]-1)))?0:w[c[d]]));
			}
			deg[d]--;
			if(deg[d]==0) q.push(d);
		}
	}
}
ll ans2[N];
void topo2(){
	ans2[1]=w[c[1]];
	queue<int> q;q.push(1);
	for(int i=1;i<=n;i++){
		for(auto d:g[i]) deg[d]++;
	}
	while(!q.empty()){
		int u=q.front();q.pop();
		for(auto d:g[u]){
			ans2[d]=max(ans2[d],ans2[u]+w[c[d]]);
			deg[d]--;
			if(deg[d]==0) q.push(d);
		}
	}
}
int main(){
	freopen("shop.in","r",stdin);
	freopen("shop.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>c[i];
	set<int> s;
	for(int i=1;i<=n;i++) s.insert(c[i]);
	for(int i=1;i<=n;i++) cin>>w[i];
	for(int j=1;j<=m;j++){
		int u,v;cin>>u>>v;
		g[u].push_back(v);
	}
	if(n<=10||m==n-1){
		dfs(1,0);
		for(int i=1;i<=n;i++) cout<<ans[i]<<"\n";
	}
	else if(s.size()<=20){
		topo();
		for(int i=1;i<=n;i++){
			ll ans=0;
			for(int j=0;j<(1<<20);j++){
				ans=max(ans,dp[i][j]);
			}
			cout<<ans<<"\n";
		}
	}
	else if(s.size()==n){
		topo2();
		for(int i=1;i<=n;i++){
			cout<<ans2[i]<<" ";
		}
	}
	else{
		dfs(1,0);
		for(int i=1;i<=n;i++) cout<<ans[i]<<"\n";
	}
	return 0;
}

