#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=150+10;
vector<pair<int,int> > g[N];
struct edge{
	int u,v;
};
vector<edge> e;
int tot=0,cnt=2,low[N],dfn[N];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
void tarjan(int u,int in_edge){
	low[u]=dfn[u]=++tot;
	for(auto d:g[u]){
		int v=d.first,num=d.second;
		if(!dfn[v]){
			tarjan(v,num);
			low[u]=min(low[u],low[v]);
			if(low[v]>dfn[u]){
				q.push({min(u,v),max(u,v)});
			}
		}
		else if(dfn[v]<dfn[u]&&num!=(in_edge^1)){
			low[u]=min(low[u],dfn[v]);
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back({v,cnt++});
		g[v].push_back({u,cnt++});
		e.push_back(edge{u,v});
		e.push_back(edge{v,u});
	}
	for(int i=1;i<=n;i++){
		if(!dfn[i]) tarjan(i,0); 
	}
	while(!q.empty()){
		cout<<q.top().first<<" "<<q.top().second<<endl;
		q.pop();
	}
	return 0;
}

