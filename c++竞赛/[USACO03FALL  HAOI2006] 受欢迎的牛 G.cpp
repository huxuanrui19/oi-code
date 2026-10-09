#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e4+10;
vector<int> g[N];
int n,m;
int tot,dfn[N],low[N];
int top,stk[N],instk[N];
int cnt,scc[N],siz[N];
int dout[N];
void tarjan(int u){
	dfn[u]=low[u]=++tot;
	stk[++top]=u;instk[u]=1;
	for(auto d:g[u]){
		if(!dfn[d]){
			tarjan(d);
			low[u]=min(low[u],low[d]);
		}
		else if(instk[d]) low[u]=min(low[u],dfn[d]);
	}
	if(low[u]==dfn[u]){
		int d;++cnt;
		do{
			d=stk[top--];
			instk[d]=0;
			scc[d]=cnt;
			siz[cnt]++;
		}while(d!=u);
	}
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
	}
	for(int i=1;i<=n;i++){
		if(!dfn[i]){
			tarjan(i);
		}
	}
	for(int i=1;i<=n;i++){
		for(auto d:g[i]){
			if(scc[d]!=scc[i]){
				dout[scc[i]]++;
			}
		}
	}
	int sum=0,ans=0;
	for(int i=1;i<=cnt;i++) if(dout[i]==0) sum++,ans=siz[i];
	if(sum==1) cout<<ans;
	else cout<<"0";
	return 0;
}

