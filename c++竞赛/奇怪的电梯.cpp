#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
const int N=2e2+10;
const int maxn=1e8;
int n,a,b,k[N];
int dis[N],vis[N];
vector<int> g[N];
void dijk(int s){
	for(int i=1;i<=n;i++) dis[i]=maxn;
	for(int i=1;i<=n;i++) vis[i]=0;
	dis[s]=0;
	priority_queue<pii,vector<pii>,greater<pii> > q;
	q.push((pii){0,s});
	while(!q.empty()){
		int u=q.top().second;q.pop();
		if(vis[u]!=0) continue;
		vis[u]=1;
		for(auto v:g[u]){
			if(dis[v]>(dis[u]+1)){
				dis[v]=dis[u]+1;
				q.push((pii){dis[v],v});
			}
		}
	}
	return;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n>>a>>b;
	for(int i=1;i<=n;i++) cin>>k[i];
	for(int i=1;i<=n;i++){
		if(k[i]==0) continue;
		if(k[i]<i) g[i].push_back(i-k[i]);
		if(k[i]+i<=n) g[i].push_back(i+k[i]);
	}
	dijk(a);
	//for(int i=1;i<=n;i++) cout<<dis[i]<<"\n";
	if(dis[b]>=maxn) cout<<"-1";
	else cout<<dis[b];
	return 0;
}

