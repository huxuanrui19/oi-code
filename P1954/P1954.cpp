#include<bits/stdc++.h>
#define pii pair<ll,int>
using namespace std;
typedef long long ll;
const int N=2e3+10;
int n,m,k[N],ind[N],d[N],vis[N],cal[N];
vector<int> g[N];
void dfs(int u){
	vis[u]=1;
	cal[u]=k[u]-d[u];
	for(auto v:g[u]){
		if(vis[v]) continue;
		d[v]=d[u]+1;
		cal[u]=min(cal[u],cal[v]);
		dfs(v);
	}
}
int cnt,s[N];
void topo_sort(){
	priority_queue<pii,vector<pii>,greater<pii> >q;
	for(int i=1;i<=n;i++) if(ind[i]==0) q.push({cal[i],i});
	while(!q.empty()){
		int u=q.top().second;q.pop();
		s[++cnt]=u;
		for(auto v:g[u]){
			ind[v]--;
			if(ind[v]==0) q.push({cal[v],v});
		}
	}
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>k[i];
	for(int i=1;i<=m;i++){
		int u,v;cin>>u>>v;
		g[u].push_back(v);
		ind[v]++;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]) dfs(i);
	}
	topo_sort();
	for(int i=1;i<=n;i++) cout<<s[i]<<" ";
	cout<<"\n";
	for(int i=1;i<=n;i++) cout<<(d[i]+1)<<" ";
	return 0;
}
