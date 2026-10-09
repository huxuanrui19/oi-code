#include<bits/stdc++.h>
#define pii pair<ll,int>
#define inf 1e18
using namespace std;
typedef long long ll;
const int N=5e3+10,M=2e5+10;
int cnt,to[M],nxt[M],head[N];ll w[M];
inline void addedge(int u,int v,ll ww){
	cnt++;
	to[cnt]=v;w[cnt]=ww;
	nxt[cnt]=head[u];
	head[u]=cnt;
}
bool vis[N][2];
ll n,r,dis[N][2];
priority_queue<pii,vector<pii>,greater<pii> > q;
void dijk(int s){
	for(int i=1;i<=n;i++) dis[i][0]=dis[i][1]=inf;
	dis[s][0]=0;
	q.push({0,s});
	while(!q.empty()){
		int u=q.top().second,uu=0;q.pop();
		uu=((u>n)?(u-n):u);
		if(vis[uu][!(uu==u)]) continue;
		vis[uu][!(uu==u)]=1;
		for(int i=head[uu];i;i=nxt[i]){
			int v=to[i],ww=w[i];
			if(u>n){
				if(dis[v][1]>dis[uu][1]+ww&&dis[v][0]!=(dis[uu][1]+ww)){
					dis[v][1]=dis[uu][1]+ww;
					q.push({dis[v][1],v+n});
				}
			}else{
				if(dis[v][0]>dis[u][0]+ww){
					dis[v][1]=dis[v][0];
					q.push({dis[v][1],v+n});
					q.push({dis[u][0]+ww,v});
					dis[v][0]=dis[u][0]+ww;
				}
				else if(dis[v][1]>dis[u][0]+ww&&(dis[v][0]!=dis[u][0]+ww)){
					dis[v][1]=dis[u][0]+ww;
					q.push({dis[v][1],v+n});
				}
			}
		}
	}
}
int main() {
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>r;
	for(int i=1;i<=r;i++){
		int a,b;ll d;
		cin>>a>>b>>d;
		addedge(a,b,d);
		addedge(b,a,d);
	}
	dijk(1);
	cout<<dis[n][1];
	return 0;
}