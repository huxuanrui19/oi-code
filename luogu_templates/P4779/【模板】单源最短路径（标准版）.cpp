#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
const ll inf=(1ll<<31)-1;
struct node{
	ll id,w;
	bool operator > (const node &a) const{
		return w>a.w;
	}
};
vector<pair<int,ll> > g[N];
int n,m,s;
ll dis[N],vis[N];
void dijk(int u){
	fill(dis+1,dis+n+1,inf);
	dis[u]=0;
	priority_queue<node,vector<node>,greater<node> > q;
	q.push((node){u,0});
	while(!q.empty()){
		ll d=q.top().id,num=q.top().w;
		q.pop();
		if(vis[d]) continue;
		vis[d]=1;
		for(auto v:g[d]){
			if(dis[v.first]>num+v.second){
				dis[v.first]=num+v.second;
				q.push((node){v.first,dis[v.first]});
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m>>s;
	for(int i=1;i<=m;i++){
		ll a,b,c;
		cin>>a>>b>>c;
		g[a].push_back({b,c});
	}
	dijk(s);
	for(int i=1;i<=n;i++){
		if(dis[i]>=inf) cout<<inf<<" ";
		else cout<<dis[i]<<" ";
	}
	return 0;
}

