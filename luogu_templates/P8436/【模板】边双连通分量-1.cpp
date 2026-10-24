#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10,M=2e6+10;
struct edge{
	int a,b;
};
int n,m;
vector<edge> e;
vector<int> g[N];
inline void addedge(int a,int b){
	e.push_back({a,b});
	g[a].push_back(e.size()-1);
}
int tot,dfn[N],low[N];
stack<int> st;
int siz,bri[M<<1],edccno[N];
vector<int> edcc[N];
void tarjan(int u,int inedg){
	dfn[u]=low[u]=++tot;
	st.push(u);
	for(auto d:g[u]){
		int v=e[d].b;
		if(!dfn[v]){
			tarjan(v,d);
			low[u]=min(low[u],low[v]);
			if(low[v]>dfn[u]){
				bri[d]=bri[d^1]=1;
			}
		}
		else if(d!=(inedg^1)) low[u]=min(low[u],dfn[v]);
	}
	if(dfn[u]==low[u]){
		siz++;
		while(1){
			int x=st.top();st.pop();
			edccno[x]=siz;
			if(x==u) break;
		}
	}
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v;cin>>u>>v;
		if(u==v) continue;
		addedge(u,v);addedge(v,u);
	}
	for(int i=1;i<=n;i++){
		if(!dfn[i]) tarjan(i,-1);
	}
	for(int i=1;i<=n;i++) edcc[edccno[i]].push_back(i);
	cout<<siz<<"\n";
	for(int i=1;i<=siz;i++){
		cout<<edcc[i].size()<<" ";
		for(auto d:edcc[i]) cout<<d<<" ";
		cout<<"\n";
	}
	return 0;
}

