#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
vector<int> g[N];
int dep[N],size[N],son[N],top[N],fa[N];
void dfs1(int u,int f){
	dep[u]=dep[f]+1;
	fa[u]=f;
	size[u]=1;
	for(auto d:g[u]){
		if(d==f) continue;
		dfs1(d,u);
		size[u]+=size[d];
		if(!son[u]||size[son[u]]<size[d]){
			son[u]=d;
		}
	}
}
void dfs2(int u,int topx){
	top[u]=topx;
	if(!son[u]) return;
	dfs2(son[u],topx);
	for(auto d:g[u]){
		if(d==fa[u]||d==son[u]) continue;
		dfs2(d,d);
	}
}
int lca(int x,int y){
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]]) swap(x,y);
		x=fa[top[x]];
	}
	return dep[x]<dep[y]?x:y;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,m,s;
	cin>>n>>m>>s;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs1(s,0);dfs2(s,s);
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		cout<<lca(u,v)<<"\n";
	}
	return 0;
}

