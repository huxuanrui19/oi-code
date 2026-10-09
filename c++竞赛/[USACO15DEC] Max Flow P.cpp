#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e4+10;
vector<int> g[N];
int f[N][20],a[N],dep[N];
void dfs1(int u,int fa){
	f[u][0]=fa;
	dep[u]=dep[fa]+1;
	for(int i=1;i<=19;i++){
		f[u][i]=f[f[u][i-1]][i-1];
	}
	for(auto d:g[u]){
		if(d==fa) continue;
		dfs1(d,u);
	}
}
int lca(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=19;i>=0;i--){
		if(dep[f[x][i]]>=dep[y]) x=f[x][i];
	}
	if(x==y) return x;
	for(int i=19;i>=0;i--){
		if(f[x][i]!=f[y][i]){
			x=f[x][i];
			y=f[y][i];
		}
	}
	return f[x][0];
}
void dfs2(int u,int fa){
	for(auto d:g[u]){
		if(d==fa) continue;
		dfs2(d,u);
		a[u]+=a[d];
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs1(1,0);
	for(int i=1;i<=k;i++){
		int s,t;
		cin>>s>>t;
		int l=lca(s,t);
		a[s]++;a[t]++;
		a[l]--;a[f[l][0]]--;
	}
	dfs2(1,0);
	int maxn=0;
	for(int i=1;i<=n;i++){
		maxn=max(maxn,a[i]);
	}
	cout<<maxn;
	return 0;
}

