#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N=1e3+10;
struct edge{
	int v,f,c;
	bool operator >(const edge &x) const{
		return c>x.c;
	}
};
vector<edge> g[N];
int n,m,flow[N],vis[N],dis[N];

int dijk(int u,int f){
	priority_queue<edge,vector<edge>,greater<edge> > q;
	memset(vis,0,sizeof(vis));
	memset(dis,0x3f,sizeof(dis));
	dis[u]=0;
	q.push({u,f,0});
	while(!q.empty()){
		edge i=q.top();
		q.pop();
		int v=i.v,c=i.c;
		if(vis[v]) continue;
		vis[v]=1;
		for(auto d:g[v]){
			if(d.f>=f&&(dis[d.v]>d.c+c)){
				dis[d.v]=d.c+c;
				q.push({d.v,f,dis[d.v]});
			}
		}
	}
	return dis[n];
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v,c,f;
		cin>>u>>v>>c>>f;
		flow[i]=f;
		g[u].push_back((edge){v,f,c});
		g[v].push_back((edge){u,f,c});
	}
	
	ll ans=0;
	for(int i=1;i<=m;i++){
		ll cnt2=dijk(1,flow[i]);
		ll cnt1=flow[i];
		ans=max(ans,(long long)(((long double)(cnt1))/((long double)(cnt2))*1e6));
	}
	cout<<ans;
	return 0;
}

