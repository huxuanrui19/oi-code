#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e4+10;
vector<int> g[N];
int tot,dfn[N],low[N];
int iscut[N];

void tarjan(int u,int root){
	low[u]=dfn[u]=++tot;
	int ch=0;
	for(auto v:g[u]){
		if(!dfn[v]){
			tarjan(v,root);
			low[u]=min(low[u],low[v]);
			if(low[v]>=dfn[u]){
				ch++;
				if(u!=root||ch>1){
					iscut[u]=1;
				}
			} 
		}
		else low[u]=min(low[u],dfn[v]);
	}
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
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
	for(int i=1;i<=n;i++){
		if(!dfn[i]) tarjan(i,i);
	}
	int sum=0;
	for(int i=1;i<=n;i++) sum+=iscut[i];
	cout<<sum<<"\n";
	for(int i=1;i<=n;i++){
		if(iscut[i]) cout<<i<<" ";
	}
	return 0;
}

