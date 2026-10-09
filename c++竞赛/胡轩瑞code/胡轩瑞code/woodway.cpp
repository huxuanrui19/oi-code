#include<bits/stdc++.h>
#define pii pair<ll,int>
using namespace std;
typedef long long ll;
const int N=5e5+10;
vector<int> g[N];
vector<pii> gt[N];
int n,m1,m2,flag1=0,flag2=0,fa[N];
vector<int> st1;
vector<int> st2;

void dfs1(int u,int fa,int v){
	st1.push_back(u);
	if(u==v){
		flag1=1;
		return;
	}
	for(auto d:g[u]){
		if(d==fa) continue;
		dfs1(d,u,v);
		if(flag1==1) return;
	}
	st1.pop_back();
} 
void dfs2(int u,int fa,int v){
	st2.push_back(u);
	if(u==v){
		flag2=1;
		return;
	}
	for(auto d:g[u]){
		if(d==fa) continue;
		dfs2(d,u,v);
		if(flag2==1) return;
	}
	st2.pop_back();
}

void dfs3(int u,int fa){
	st1.push_back(u);
	for(auto d:g[u]){
		if(d==fa) continue;
		dfs3(d,u);
	}
}
void dfs4(int u,int fa){
	st2.push_back(u);
	for(auto d:g[u]){
		if(d==fa) continue;
		dfs4(d,u);
	}
}

ll dis[N],vis[N]; 
void dijk(int s){
	memset(dis,0x3f,sizeof(dis));
	dis[s]=0;
	priority_queue<pii,vector<pii>,greater<pii> > q;
	q.push({0,s});
	while(!q.empty()){
		int u=q.top().second;q.pop(); 
		if(vis[u]) continue;
		vis[u]=1;
		for(auto d:gt[u]){
			if(dis[d.second]>dis[u]+d.first){
				dis[d.second]=dis[u]+d.first;
				q.push({dis[d.second],d.second});
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("woodway.in","r",stdin);
	freopen("woodway.out","w",stdout);
	cin>>n>>m1>>m2;
	for(int i=1,u,v,w;i<n;i++){
		cin>>u>>v>>w;
		fa[v]=u;
		g[u].push_back(v);
		g[v].push_back(u);
		gt[u].push_back({w,v}); 
	}
	for(int i=1;i<=m1;i++){
		ll u,v,a,b,w;
		cin>>u>>v>>a>>b>>w;
		flag1=flag2=0;
		dfs1(u,0,v);
		dfs2(a,0,b);
		for(auto d1:st1){
			for(auto d2:st2){
				gt[d1].push_back({w,d2});
			}
		}
		st1.clear();st2.clear();
	}
	for(int i=1;i<=m2;i++){
		ll u,v,w;cin>>u>>v>>w;
		dfs3(u,fa[u]);dfs4(v,fa[v]);
		for(auto d1:st1){
			for(auto d2:st2){
				gt[d1].push_back({w,d2});
			}
		}
		st1.clear();st2.clear();
	}
	dijk(1);
	for(int i=1;i<=n;i++) cout<<dis[i]<<" "; 
	return 0;
}

