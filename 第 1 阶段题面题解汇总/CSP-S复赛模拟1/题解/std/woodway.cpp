#include<bits/stdc++.h>
#define pb push_back
#define ls (now<<1)
#define rs ((now<<1)|1)
#define mid ((l+r)>>1)
#define maxn 500005
#define ll long long
using namespace std;
//树&树剖部分
int n,m1,m2;
int u[maxn],v[maxn],a[maxn],b[maxn],w[maxn],id[maxn];
vector<pair<int,int>> edge[maxn];
int siz[maxn],dep[maxn],FA[maxn],fa[maxn],IN[maxn],OUT[maxn],tot;

//线段树部分 
ll dis[maxn<<2]; //最短路 
basic_string<int> guan[maxn<<2]; //每个位置对应的管道ID

//求dep,siz,fa 
void dfs1(int x,int f)
{
	dep[x]=dep[f]+1; fa[x]=f; siz[x]=1;
	for (pair<int,int> tt:edge[x]) if (tt.first!=f) {dfs1(tt.first,x); siz[x]+=siz[tt.first];}
}
//剖
void dfs2(int x,int f) 
{
	IN[x]=++tot; FA[x]=f; id[tot]=x; //dfs序上第tot个点是x 
	int hs=-1;
	for (pair<int,int> tt:edge[x]) 
	if (tt.first!=fa[x] && (hs==-1 || siz[tt.first]>siz[hs]))
		hs=tt.first;
	if (hs!=-1) dfs2(hs,f);
	for (pair<int,int> tt:edge[x]) 
	if (tt.first!=fa[x] && tt.first!=hs)
		dfs2(tt.first,tt.first);
	OUT[x]=tot;
}

//给区间添加编号为id的边 
void addedge(int now,int l,int r,int L,int R,int id)
{
	if (L<=l && r<=R) {guan[now]+=id; return;} //你子树内都有这个了
	if (L<=mid) addedge(ls,l,mid,L,R,id);
	if (mid+1<=R) addedge(rs,mid+1,r,L,R,id);
	return; 
}

//x到y,id号边 
void ins1(int x,int y,int id)
{
	while (true)
	{
		if (dep[FA[x]]<dep[FA[y]] || (dep[FA[x]]==dep[FA[y]] && dep[x]<dep[y])) swap(x,y);
		//到同一条重链了 
		if (FA[x]==FA[y]) {addedge(1,1,n,IN[y],IN[x],id); return;}
		//否则，x先跳到重链头再说
		addedge(1,1,n,IN[FA[x]],IN[x],id);
		x=fa[FA[x]];
	}
	return;
}  

void init()
{
	cin>>n>>m1>>m2;
	int x,y,z;
	for (int i=1;i<n;i++) {cin>>x>>y>>z; edge[x].pb({y,z}); edge[y].pb({x,z});}
	dfs1(1,1);
	dfs2(1,1);
	for (int i=1;i<=m1;i++)
	{
		cin>>u[i]>>v[i]>>a[i]>>b[i]>>w[i];
		ins1(u[i],v[i],i); //u[i]到v[i],i号边 
	}
	for (int i=m1+1;i<=m1+m2;i++)
	{
		cin>>u[i]>>v[i]>>w[i];
		addedge(1,1,n,IN[u[i]],OUT[u[i]],i);
	}
}

//最短路的部分，不难写，好长，我* 
priority_queue<pair<ll,ll>> Q; //{dis,id} 管道的id 
int vis[maxn]; //记录每条管道是否用过 
void ADD2(int now,int l,int r,int pos,ll dis)
{
	if (l<=pos && pos<=r)
	{
		for (int id:guan[now]) if (!vis[id]) Q.push({-dis-w[id],id}),vis[id]=1;
		guan[now].clear();
	}
	if (l==r) return;
	if (pos<=mid) ADD2(ls,l,mid,pos,dis); else ADD2(rs,mid+1,r,pos,dis);
}

//添加所有x相关的边 
void ADD(int x,ll dis)
{
	//先加直接的边
	for (auto tt:edge[x]) 
	if (tt.first!=fa[x]) Q.push({-dis-tt.second,-tt.first}); 
	//再加相关的管道
	ADD2(1,1,n,IN[x],dis); 
} 

ll ans[maxn]; //记录答案 
//把区间没更新的更新成v 
void modify(int now,int l,int r,int L,int R,ll v)
{
	if (dis[now]>0) return;
	if (l==r) {dis[now]=v; ans[id[l]]=v; ADD(id[l],v); return;}
	if (L<=mid) modify(ls,l,mid,L,R,v);
	if (mid+1<=R) modify(rs,mid+1,r,L,R,v);
	dis[now]=min(dis[ls],dis[rs]);
	return;
}

int used[maxn];
//x到y路径，更新成dis 
void ins2(int x,int y,ll dis)
{
	while (true)
	{
		if (dep[FA[x]]<dep[FA[y]] || (dep[FA[x]]==dep[FA[y]] && dep[x]<dep[y])) swap(x,y);
		//到同一条重链了，更新这一段答案好了 
		if (FA[x]==FA[y]) 
		{
			if (!used[x]) modify(1,1,n,IN[y],IN[x],dis); 
			return;
		}
		//否则，x先跳到重链头再说
		if (!used[x]) modify(1,1,n,IN[FA[x]],IN[x],dis),used[x]=1;
		x=fa[FA[x]];
	}
	return;
}

void work()
{
	modify(1,1,n,IN[1],IN[1],1); //先把1的最短路更新成0+1啦
	while (!Q.empty() && dis[1]==0) //当dis[1]>0就说明更新完了 
	{
		pair<ll,ll> tt=Q.top(); Q.pop();
		ll dis=-tt.first,id=tt.second;
		if (id<0) //我爱单点 
		{
			id=-id;
			modify(1,1,n,IN[id],IN[id],dis);
		}
		else if (id<=m1) //更新a[id],b[id]这一段 
		{
			ins2(a[id],b[id],dis);
		}
		else //更新v[id]的子树，我也喜欢
			modify(1,1,n,IN[v[id]],OUT[v[id]],dis); 
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	init();
	work();
	for (int i=1;i<=n;i++) cout<<ans[i]-1<<" "; cout<<endl;
}