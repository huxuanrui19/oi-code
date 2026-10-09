#include<bits/stdc++.h>
#define pii pair<ll,int>
using namespace std;
typedef long long ll;
const ll inf=1e18;
const int N=1e4+10,H=110;
vector<pii> g[N*H];
ll n,m,h,dis[N*H],vis[N*H],hi[N];
void dijk(int s){
	fill(dis+1,dis+N*H,inf);
	fill(vis+1,vis+N*H,inf);
	priority_queue<pii,vector<pii>,greater<pii> > q;
	dis[s]=0;q.push({0,s});
	while(!q.empty()){
		int u=q.top().second;ll val=q.top().first;q.pop();
		if(vis[u]==1) continue;
		vis[u]=1;
		for(auto d:g[u]){
			ll v=d.second,w=d.first;
			if(dis[v]>w+val){
				dis[v]=w+val;
				q.push({dis[v],v});
			}
		}
	}
	return;
}
int main(){
	freopen("climb.in","r",stdin);
	freopen("climb.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m>>h;
	for(int i=1;i<=n;i++) cin>>hi[i];
	for(int i=1;i<=m;i++){
		ll u,v,t;cin>>u>>v>>t;
		for(int j=0;j<=h;j++){
			if(hi[u]>hi[v]) g[j*n+u].push_back({t,v});
			else if(j+(hi[v]-hi[u])<=h) g[j*n+u].push_back({t,(j+(hi[v]-hi[u]))*n+v}); 
		}
		for(int j=0;j<=h;j++){
			if(hi[v]>hi[u]) g[j*n+v].push_back({t,u});
			else if(j+(hi[u]-hi[v])<=h) g[j*n+v].push_back({t,(j+(hi[u]-hi[v]))*n+u}); 
		}
	}
	dijk(1);
	for(int i=2;i<=n;i++){
		ll ans=inf;
		for(int j=0;j<=h;j++) ans=min(ans,dis[j*n+i]);
		if(ans==inf) cout<<"-1";
		else cout<<ans;
		cout<<" ";
	}
	return 0;
}

