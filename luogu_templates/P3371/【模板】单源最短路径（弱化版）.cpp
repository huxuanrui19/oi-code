#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e4+10;
const ll inf=(1ll<<31)-1;
vector<pair<int,ll> >g[N];
int n,m,s;
ll dis[N],inq[N];
void spfa(int s){
	fill(dis+1,dis+n+1,inf);
	queue<int> q;
	dis[s]=0;
	q.push(s);
	inq[s]=1;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		inq[u]=0;
		for(auto e:g[u]){
			int d=e.first;
			ll num=e.second;
			if(dis[d]>num+dis[u]){
				dis[d]=num+dis[u];
				if(!inq[d]){
					q.push(d);
					inq[d]=1;
				}
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
	spfa(s);
	for(int i=1;i<=n;i++){
		cout<<dis[i]<<" ";
	}
	return 0;
}

