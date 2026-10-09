#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e3+10;
const ll inf=1e16;
int n,m,c[N],vis[N];
ll a,b,w[N][N],d[N];
vector<pair<int,ll> > g[N];
vector<pair<int,ll> > gt[N];
struct edge{
	int u;
	ll dis;
	bool operator > (const edge &x)const{
		return dis>x.dis;
	}
};
void dij(int s){
	priority_queue<edge,vector<edge>,greater<edge> >q;
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++) w[s][i]=inf;
	w[s][s]=0;
	q.push({s,0});
	while(!q.empty()){
		int u=q.top().u;
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(auto d:g[u]){
			int v=d.first;
			ll val=d.second;
			if(w[s][v]>(w[s][u]+val)){
				w[s][v]=w[s][u]+val;
				q.push({v,w[s][v]});
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v,wi;
		cin>>u>>v>>wi;
		g[u].push_back({v,wi});
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	cin>>a>>b;
	for(int i=1;i<=n;i++){
		dij(i);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			if(w[i][j]<=a){
				gt[i].push_back({j,w[i][j]});
			}
		}
	}
	priority_queue<edge,vector<edge>,greater<edge> >q;
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++) d[i]=inf;
	d[1]=0;
	q.push({1,0});
	while(!q.empty()){
		int u=q.top().u;
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(auto x:gt[u]){
			int v=x.first;
			ll val=x.second;
			if((val)%(a+b)+d[u]<=a){
				if(val+d[u]<d[v]){
					d[v]=val+d[u];
					q.push({v,d[v]});
				}
			}
			else{
				if(c[u]==1) continue;
				ll cnt=a+b-(d[u]%(a+b));
				if(val+d[u]+cnt<d[v]){
					d[v]=val+d[u]+cnt;
					q.push({v,d[v]});
				}
			}
		}
	}
	if(d[n]>=inf) cout<<"-1";
	else cout<<d[n];
	return 0;
}

