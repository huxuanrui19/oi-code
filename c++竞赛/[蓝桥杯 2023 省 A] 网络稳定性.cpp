#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
vector<pair<int,ll> >g[N];
struct edge{
	int u,v;
	ll w;
	bool operator <(const edge &x) const{
		return w>x.w;
	}
}e[N*3];
int n,m,q,cnt,fa[N],vis[N];
int find(int x){
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y){
	x=find(x);y=find(y);
	fa[x]=y;
}
void kru(){
	sort(e+1,e+m+1);
	int tot=0;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		int u=e[i].u,v=e[i].v;
		ll w=e[i].w;
		if(find(u)==find(v)) continue;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
		merge(u,v);
		tot++;
		if(tot==(n-1)) return;
	}
	return;
}
ll dep[N],f[N][20],minn[N][20];
void dfs(int u,int father){
	dep[u]=dep[father]+1;
	f[u][0]=father;
	vis[u]=1;
	for(int i=1;(1<<i)<dep[u];i++){
		f[u][i]=f[f[u][i-1]][i-1];
		minn[u][i]=min(minn[f[u][i-1]][i-1],minn[u][i-1]);
	}
	for(auto d:g[u]){
		if(d.first==father) continue;
		minn[d.first][0]=d.second;
		dfs(d.first,u);
	}
}
ll query(ll x,ll y){
	if(x==y) return 0; 
	if(dep[x]<dep[y]) swap(x,y);
	ll ans=1e14+7;
	for(int i=19;i>=0;i--){
		if(dep[f[x][i]]>=dep[y]){
			ans=min(ans,minn[x][i]);
			x=f[x][i];
		}
	}
	if(x==y) return ans;
	for(int i=19;i>=0;i--){
		if(f[x][i]!=f[y][i]){
			ans=min(ans,minn[x][i]);
			ans=min(ans,minn[y][i]);
			x=f[x][i];y=f[y][i];
		}
	}
	return min({ans,minn[x][0],minn[y][0]});
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m>>q;
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	kru();
	memset(minn,0x3f,sizeof(minn));
	for(int i=1;i<=n;i++){
		if(!vis[i]) dfs(i,0);
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		if(find(x)!=find(y)) cout<<"-1\n";
		else cout<<query(x,y)<<"\n";
	}
	return 0;
}

