#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
const int N=1e5+10;
int n,m,mark=1,tot,fa[N],idx[N],flag[N];
ll ans=0;
vector<pair<int,int> > gt[N];
struct edge{
	int u,v,id;
	ll w;
	bool operator <(const edge &x) const{
		return w<x.w;
	}
}e[N],et[N];

int find(int x){
	if(x==fa[x]) return fa[x];
	else return fa[x]=find(fa[x]);
}
void merge(int u,int v){
	u=find(u);v=find(v);
	fa[u]=v;
}

void kruskal(){
	sort(et+1,et+m+1);
	for(int i=1;i<=m;i++) idx[et[i].id]=i;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		int u=et[i].u,v=et[i].v;
		ll w=et[i].w;
		if(find(u)==find(v)) continue;
		else{
			gt[u].push_back({v,et[i].id});
			gt[v].push_back({u,et[i].id});
			flag[i]=1;
			merge(u,v);
			ans+=w;
			tot++;
		}
	}
	if(tot<(n-1)) mark=0;
}

int f[N],dep[N],re[N];
ll rep[N];
void dfs(int u,int fat){
	f[u]=fat;
	dep[u]=dep[fat]+1;
	for(auto d:gt[u]){
		if(d.fi==fat) continue;
		dfs(d.fi,u);
		re[d.se]=d.fi;			//±ﬂ»®->µ„»® 
	}
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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	for(int i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		et[i]=(edge){u,v,i,w};
		e[i]=et[i];
	}
	kruskal();
	if(mark==0){
		for(int i=1;i<=m;i++){
			cout<<"-1\n";
		}
	}
	else{
		dfs(1,0);
		for(int i=1;i<=n;i++){
			fa[i]=i;
		}
		for(int i=1;i<=n;i++) rep[i]=-1;
		for(int i=1;i<=m;i++){
			if(!flag[i]){
				update(et[i].u,et[i].v,et[i].w);
			}
		}
		for(int i=1;i<=m;i++){
			if(!flag[idx[i]]) cout<<ans<<"\n";
			else{
				if(rep[re[i]]!=-1)cout<<ans-e[i].w+rep[re[i]]<<"\n";
				else cout<<"-1\n";
			}
		}
	}
	return 0;
}
