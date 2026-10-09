#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e3+10;
int n,m;
vector<pair<int,int> > g[N];
int vis[N],dis[N],inq[N];
void init(){
	for(int i=0;i<N;i++){
		g[i].clear();
		vis[i]=0;
		inq[i]=0;
		dis[i]=1e9;
	}
}
void spfa(int u){
	dis[u]=0;
	queue<int> q; 
	vis[u]++;
	q.push(u);
	while(!q.empty()){
		int v=q.front();
		q.pop();
		inq[v]=0;
		for(auto e:g[v]){
			int d=e.first,w=e.second;
			if(dis[d]>dis[v]+w){
				dis[d]=dis[v]+w;
				if(!inq[d]){
					q.push(d);
					inq[d]=1;
					vis[d]++;
					if(vis[d]>=n){
						cout<<"YES\n";
						return;
					}
				}
			}
		}
	}
	cout<<"NO\n";
	return;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		init();
		cin>>n>>m;
		for(int i=1;i<=m;i++){
			int u,v,w;
			cin>>u>>v>>w;
			g[u].push_back({v,w});
			if(w>=0) g[v].push_back({u,w});
		}
		spfa(1);
	}
	return 0;
}

