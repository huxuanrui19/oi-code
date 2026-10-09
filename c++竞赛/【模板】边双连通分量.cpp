#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10,M=4e6+10;
vector<pair<int,int> > g[N];
struct edge{
	int u,v;
};
vector<edge> e;
vector<int> edcc[N];
stack<int> st;
int tot=0,cnt=2,low[N],dfn[N];
int num,edccno[N];
int bri[M],d[N];
//priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
void tarjan(int u,int in_edge){
	low[u]=dfn[u]=++tot;
	st.push(u);
	for(auto d:g[u]){
		int v=d.first,idx=d.second;
		if(!dfn[v]){
			tarjan(v,idx);
			low[u]=min(low[u],low[v]);
			if(low[v]>dfn[u]){
				bri[in_edge]=bri[in_edge^1]=1;
				//q.push({min(u,v),max(u,v)});
			}
		}
		else if(dfn[v]<dfn[u]&&idx!=(in_edge^1)){
			low[u]=min(low[u],dfn[v]);
		}
	}
	if(dfn[u]==low[u]){
		++num;
		while(1){
			int v=st.top();st.pop();
			edccno[v]=num;
			edcc[num].push_back(v);
			if(v==u) break;
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
	cout<<num<<"\n";
	for(int i=1;i<=num;i++){
		cout<<edcc[i].size()<<" ";
		for(auto u:edcc[i]){
			cout<<u<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
