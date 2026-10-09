#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=150+10;
vector<int> g[N];
int times=0,low[N],dfn[N];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
void tarjan(int u,int fa){
	low[u]=dfn[u]=++times;
	for(auto v:g[u]){
		if(!dfn[v]){
			tarjan(v,u);
			low[u]=min(low[u],low[v]);
			if(low[v]>dfn[u]){
				q.push({min(u,v),max(u,v)});
			}
		}
		else if(dfn[v]<dfn[u]&&v!=fa){
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
		g[u].push_back(v);
		g[v].push_back(u);
	}
	tarjan(1,1);
	while(!q.empty()){
		cout<<q.top().first<<" "<<q.top().second<<endl;
		q.pop();
	}
	return 0;
}

