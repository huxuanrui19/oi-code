#include<bits/stdc++.h>
#define pii pair<ll,int>
using namespace std;
typedef long long ll;
const int M=2e4+10,N=1e4+10;
struct edge{
	int u,v;ll w;
	bool operator <(const edge &x) const{
		return w<x.w;
	}
}e[M];
int n,m,s,t,fa[N],dep[N],val[N];
int find(int u){
	if(u==fa[u]) return u;
	return fa[u]=find(fa[u]);
}
void merge(int u,int v){
	u=find(u);v=find(v);
	fa[u]=v;
}
vector<pii> tr[N];
void dfs(int u,int fath){
	fa[u]=fath;dep[u]=dep[fath]+1;
	for(auto d:tr[u]) if(d.second!=fath){val[d.second]=d.first;dfs(d.second,u);}
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m>>s>>t;
	for(int i=1;i<=m;i++){
		int u,v;ll w;
		cin>>u>>v>>w;
		e[i]=(edge){u,v,w};
	}
	sort(e+1,e+m+1);
	int tot=0;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		edge ed=e[i];
		int u=ed.u,v=ed.v,w=ed.w;
		if(find(u)==find(v)) continue;
		tot++;merge(u,v);
		tr[u].push_back({w,v});
		tr[v].push_back({w,u});
		if(tot==n-1) break;
	}
	dfs(1,0);
	int ans=0;
	while(s!=t){
		if(dep[s]<dep[t]) swap(s,t);
		ans=max(ans,val[s]);
		s=fa[s];
	}
	cout<<ans;
	return 0;
}

