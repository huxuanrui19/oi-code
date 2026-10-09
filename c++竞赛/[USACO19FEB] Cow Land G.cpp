#include<bits/stdc++.h>
#define ls(p) (p)<<1
#define rs(p) (p)<<1|1
using namespace std;
typedef long long ll;
const int N=1e5+10;
vector<int> g[N];
ll n,m,cnt,dfn[N],idx[N],fa[N],siz[N],top[N],son[N],dep[N];
void dfs1(int u,int v,int depth){
	fa[u]=v;dep[u]=depth;
	siz[u]++;
	for(auto d:g[u]){
		if(d==v) continue;
		dfs1(d,u,depth+1);
		siz[u]+=siz[d];
		if(siz[d]>siz[son[u]]) son[u]=d;
	}
	return;
}
void dfs2(int u,int v){
	top[u]=v;dfn[u]=++cnt;idx[cnt]=u;
	if(son[u]==0) return;
	dfs2(son[u],v);
	for(auto d:g[u]){
		if(d==fa[u]||d==son[u]) continue;
		dfs2(d,d);
	}
	return;
}
//以上为树链剖分，以下为线段树
ll a[N],tree[N<<2];
void push_up(int u){
	tree[u]=tree[ls(u)]^tree[rs(u)];
}
void build(int p,int pl,int pr){
	if(pl==pr){
		tree[p]=a[idx[pl]];
		return;
	}
	int mid=(pl+pr)>>1;
	build(ls(p),pl,mid);
	build(rs(p),mid+1,pr);
	push_up(p);
}
void update(int p,int pl,int pr,int pos,ll val){
	if(pl==pr){
		tree[p]=val;
		return;
	}
	int mid=(pl+pr)>>1;
	if(pos<=mid) update(ls(p),pl,mid,pos,val);
	else update(rs(p),mid+1,pr,pos,val);
	push_up(p);
}
ll query(int p,int pl,int pr,int L,int R){
	if(L>R||L>pr||R<pl) return 0;
	if(L<=pl&&pr<=R) return tree[p];
	ll sum=0;int mid=(pl+pr)>>1;
	if(L<=mid) sum^=query(ls(p),pl,mid,L,R);
	if(R>mid) sum^=query(rs(p),mid+1,pr,L,R);
	return sum; 
}
void update_node(int p,int val){update(1,1,n,dfn[p],val);}
ll query_path(int u,int v){
	ll res=0;
	while(top[u]!=top[v]){
		if(dep[top[u]]<dep[top[v]]) swap(u,v);
		res^=query(1,1,n,dfn[top[u]],dfn[u]);
		u=fa[top[u]];
	}
	if(dep[u]<dep[v]) swap(u,v);
	//cout<<res<<endl;
	res^=query(1,1,n,dfn[v],dfn[u]);
	return res;
}
int main(){
	//freopen("P6098_2.in","r",stdin);
	//freopen("P6098_21.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n-1;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs1(1,0,1);dfs2(1,1);build(1,1,n);
	while(m--){
		ll op,i,j;
		cin>>op>>i>>j;
		if(op==1) update_node(i,j);
		else cout<<query_path(i,j)<<"\n";
	}
	return 0;
}
