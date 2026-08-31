#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
const int N=1e5+10,M=3e5;
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
int bri[M];
priority_queue<pii,vector<pii>,greater<pii> > q;
void tarjan(int u,int inedg){
	dfn[u]=low[u]=++tot;
	for(auto d:g[u]){
		int v=e[d].b;
		if(!dfn[v]){
			tarjan(v,d);
			low[u]=min(low[u],low[v]);
			if(low[v]>dfn[u]){
				q.push({min(u,v),max(u,v)});
			}
		}
		else if(d!=(inedg^1)) low[u]=min(low[u],dfn[v]);
	}
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int a,b;cin>>a>>b;
		addedge(a,b);addedge(b,a);
	}
	for(int i=1;i<=n;i++){
		if(!dfn[i]) tarjan(i,-1);
	}
	while(!q.empty()){
		cout<<q.top().first<<" "<<q.top().second<<"\n";
		q.pop();
	}
	return 0;
}
