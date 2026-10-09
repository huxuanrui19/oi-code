#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
int n,m;
vector<int> g[N],gt[N];
vector<int> dcc[N];
int tot,dfn[N],low[N];
stack<int> st;
int cnt,num,cut[N],id[N];
void tarjan(int u,int root){
	dfn[u]=low[u]=++tot;
	st.push(u);
	if(!g[u].size()){
		dcc[++cnt].push_back(u);
	}
	
	int ch=0;
	for(auto v:g[u]){
		if(!dfn[v]){
			tarjan(v,root);
			low[u]=min(low[u],low[v]);
			if(low[v]>=dfn[u]){
				ch++;
				if(ch>1||root!=u) cut[u]=1;
				cnt++;
				while(1){
					int w=st.top();st.pop();
					dcc[cnt].push_back(w);
					if(w==v) break;
				}
				dcc[cnt].push_back(u);
			}
		}
		else low[u]=min(low[u],dfn[v]);
	}
	
	return;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		if(u==v) continue;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int i=1;i<=n;i++){
		if(!dfn[i]) tarjan(i,i);
	}
	num=cnt;
	for(int i=1;i<=n;i++){
		if(cut[i]) id[i]=++num;
	}
	for(int i=1;i<=cnt;i++){
		for(auto j:dcc[i]){
			if(cut[j]){
				gt[i].push_back(id[j]);
				gt[id[j]].push_back(i);
			}
		}
	}
	cout<<cnt<<"\n";
	for(int i=1;i<=cnt;i++){
		cout<<dcc[i].size()<<" ";
		for(auto d:dcc[i]) cout<<d<<" ";
		cout<<"\n";
	}
	return 0;
}

