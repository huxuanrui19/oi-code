#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
struct edge{
	int u,v,id;
	ll w;
	bool operator <(const edge &x) const{
		return w<x.w;
	}
}e[N],et[N];
int fa[N];
int find(int x){
	if(x==fa[x]) return x;
	else return fa[x]=find(fa[x]);
}
void merge(int x,int y){
	x=find(x);y=find(y);
	fa[x]=y;
}
vector<pair<int,ll>> g[N];
ll n,m,ans=0,tot,idx[N],flag[N];
void kru(){
	sort(et+1,et+m+1);
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++) idx[et[i].id]=i;
	for(int i=1;i<=m;i++){
		int u=et[i].u,v=et[i].v;
		ll w=et[i].w;
		if(find(u)==find(v)) continue;
		ans+=w;
		tot++;
		merge(u,v); 
		flag[i]=1;
		g[u].push_back({v,et[i].id});
		g[v].push_back({u,et[i].id});
	}
	return;
}
int f[N],rep[N],dep[N],up[N];
void dfs(int u,int father){
	f[u]=father;
	dep[u]=dep[father]+1;
	for(auto d:g[u]){
		if(d.first==father) continue;
		dfs(d.first,u);
		up[d.second]=d.first;
	}
	return;
}
void update(int u,int v,int w){
	u=find(u);v=find(v);
	while(u!=v){
		if(dep[u]<dep[v]) swap(u,v);
		rep[u]=w;
		merge(u,find(f[u]));
		u=find(u);
	}
	return;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v;
		ll w;
		cin>>u>>v>>w;
		e[i]=(edge){u,v,i,w};
		et[i]=e[i];
	}
	kru();
	if(tot<(n-1)){
		for(int i=1;i<=m;i++) cout<<"-1\n";
		return 0;
	}
	dfs(1,0);
	for(int i=1;i<=n;i++) fa[i]=i,rep[i]=-1;
	for(int i=1;i<=m;i++){
		if(!flag[i]) update(et[i].u,et[i].v,et[i].w);
	}
	for(int i=1;i<=m;i++){
		if(!flag[idx[i]]) cout<<ans<<"\n";
		else{
			if(rep[up[i]]!=-1) cout<<ans-e[i].w+rep[up[i]]<<"\n";
			else cout<<"-1\n";
		}
	}
	return 0;
}

