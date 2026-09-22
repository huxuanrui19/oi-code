#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,u,v,ans,idx,x,y,z,sum[N],tag[N<<2],val[N<<2],fa[N][20],dep[N],dfn[N],out[N];
vector<int> G[N];
struct Node{int l,r,w;};
vector<Node> d[N];
void dfs(int x,int f){
	fa[x][0]=f;dep[x]=dep[f]+1;
	for(int i=1;i<=19;i++)fa[x][i]=fa[fa[x][i-1]][i-1];
	dfn[x]=++idx;
	for(auto v:G[x]){
		if(v!=f)dfs(v,x);
	}out[x]=idx;
}
inline void pushup(int o){
	val[o]=max(val[o<<1],val[o<<1|1]);
}
inline void puttag(int o,int x){
	tag[o]+=x;val[o]+=x;
}
inline void pushdown(int o){
	if(!tag[o])return;
	puttag(o<<1,tag[o]);puttag(o<<1|1,tag[o]);
	tag[o]=0;
}
void update(int o,int l,int r,int ql,int qr,int x){
	if(ql<=l&&r<=qr){puttag(o,x);return;}
	int mid=(l+r)>>1;pushdown(o);
	if(ql<=mid)update(o<<1,l,mid,ql,qr,x);
	if(qr>mid)update(o<<1|1,mid+1,r,ql,qr,x);
	pushup(o);
}
inline void add(int l,int r,int ql,int qr,int w){
	if(l<=r&&ql<=qr){
		d[l].push_back({ql,qr,w});
		d[r+1].push_back({ql,qr,-w});
	}
}
inline int get(int x,int y){
	int k=dep[x]-dep[y]-1;
	for(int i=0;i<=19;i++)if(k&(1<<i))x=fa[x][i];
	return x;
}
int main(){
	freopen("keytrail.in","r",stdin);
	freopen("keytrail.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=2;i<=n;i++){
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}dfs(1,0);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&x,&y,&z);
		if(x==y){
			add(1,dfn[x]-1,dfn[x],out[x],z);
			add(out[x]+1,n,dfn[x],out[x],z);
			add(dfn[x],out[x],1,n,z);sum[x]+=z;
			continue;
		}
		if(dfn[x]<=dfn[y]&&out[y]<=out[x]){
			int p=get(y,x);
			add(1,dfn[p]-1,dfn[y],out[y],z);
			add(out[p]+1,n,dfn[y],out[y],z);
		}else if(dfn[y]<=dfn[x]&&out[x]<=out[y]){
			int p=get(x,y);
			add(dfn[x],out[x],1,dfn[p]-1,z);
			add(dfn[x],out[x],out[p]+1,n,z);
		}else add(dfn[x],out[x],dfn[y],out[y],z); 
	}
	for(int x=1;x<=n;x++){
		for(auto v:G[x]){
			if(v==fa[x][0])continue;
			add(dfn[v],out[v],dfn[v],out[v],-sum[x]);
		}
	} 
	for(int i=1;i<=n;i++){
		for(auto it:d[i])update(1,1,n,it.l,it.r,it.w);
		ans=max(ans,val[1]);
	}printf("%d\n",ans);
	return 0;
} 
