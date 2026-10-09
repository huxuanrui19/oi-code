#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
inline int ls(int x){return x<<1;}
inline int rs(int x){return x<<1|1;}
int n,m,r;
ll mod;

//�߶��� 
ll tree[N<<2],tag[N<<2],w[N],a[N];
void push_up(int p){
	tree[p]=(tree[ls(p)]+tree[rs(p)])%mod;
}
void build(int p,int pl,int pr){
	if(pl==pr){
		tree[p]=w[pl];
		return;
	}
	int mid=(pl+pr)>>1;
	build(ls(p),pl,mid);
	build(rs(p),mid+1,pr);
	push_up(p);
}
void addtag(int p,int pl,int pr,int d){
	tag[p]+=d;
	tree[p]=(tree[p]+(pr-pl+1)*d)%mod;
}
void push_down(int p,int pl,int pr){
	if(tag[p]){
		int mid=(pl+pr)>>1;
		addtag(ls(p),pl,mid,tag[p]);
		addtag(rs(p),mid+1,pr,tag[p]);
		tag[p]=0;
	}
	return;
}
void update(int l,int r,int p,int pl,int pr,ll d){
	if(l<=pl&&r>=pr){
		addtag(p,pl,pr,d);
		return;
	}
	push_down(p,pl,pr);
	int mid=(pl+pr)>>1;
	if(mid>=l) update(l,r,ls(p),pl,mid,d);
	if(mid<r) update(l,r,rs(p),mid+1,pr,d);
	push_up(p);
}
ll query(int l,int r,int p,int pl,int pr){
	if(l<=pl&&r>=pr){
		return tree[p];
	}
	push_down(p,pl,pr);
	ll ans=0;
	int mid=(pl+pr)>>1;
	if(mid>=l) ans=(ans+query(l,r,ls(p),pl,mid))%mod;
	if(mid<r) ans=(ans+query(l,r,rs(p),mid+1,pr))%mod;
	return ans;
}

//�����ʷ�
vector<int> g[N];
int id=0,dfn[N],dep[N],fa[N],son[N],top[N],siz[N];
void dfs1(int u,int f){
	dep[u]=dep[f]+1;
	siz[u]=1;
	fa[u]=f;
	for(auto d:g[u]){
		if(d==f) continue;
		dfs1(d,u);
		siz[u]+=siz[d];
		if(!son[u]||siz[son[u]]<siz[d]){
			son[u]=d;
		}
	}
}
void dfs2(int u,int topx){
	dfn[u]=++id;
	w[dfn[u]]=a[u];
	top[u]=topx;
	if(!son[u]) return;
	dfs2(son[u],topx);
	for(auto d:g[u]){
		if(d==fa[u]||d==son[u]) continue;
		dfs2(d,d);
	}
}

//�޸�+��ѯ����
void update_range(int x,int y,int d){
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]]) swap(x,y);
		update(dfn[top[x]],dfn[x],1,1,n,d);
		x=fa[top[x]];
	}
	if(dep[x]>dep[y]) swap(x,y);
	update(dfn[x],dfn[y],1,1,n,d);
}
ll query_range(int x,int y){
	ll ans=0;
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]]) swap(x,y);
		ans=(ans+query(dfn[top[x]],dfn[x],1,1,n))%mod;
		x=fa[top[x]];
	}
	if(dep[x]>dep[y]) swap(x,y);
	ans=(ans+query(dfn[x],dfn[y],1,1,n))%mod;
	return ans;
}
void update_tree(int x,ll d){
	update(dfn[x],dfn[x]+siz[x]-1,1,1,n,d);
}
ll query_tree(int x){
	return query(dfn[x],dfn[x]+siz[x]-1,1,1,n);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m>>r>>mod;
	for(int i=1;i<=n;i++)  cin>>a[i];
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
	dfs1(r,0);
	dfs2(r,r);
	build(1,1,n);
	for(int i=1;i<=m;i++){
		int opt,x,y;
		cin>>opt>>x;
		if(opt==1){
			ll d;
			cin>>y>>d;
			update_range(x,y,d);
		}
		else if(opt==2){
			cin>>y;
			cout<<query_range(x,y)<<"\n";
		}
		else if(opt==3){
			ll d;
			cin>>d;
			update_tree(x,d);
		}
		else cout<<query_tree(x)<<"\n";
	}
	return 0;
}

