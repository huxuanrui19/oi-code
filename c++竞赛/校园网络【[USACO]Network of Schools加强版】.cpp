#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e4+10;
vector<int> g[N];
int dfn[N],low[N],tot;
int stk[N],instk[N],top;
int scc[N],siz[N],cnt;
void tarjan(int u){
	dfn[u]=low[u]=++tot;
	stk[++top]=u,instk[u]=1;
	
	for(auto d:g[u]){
		if(!dfn[d]){
			tarjan(d);
			low[u]=min(low[u],low[d]);
		}
		else if(instk[d]) low[u]=min(low[u],dfn[d]);
	}
	
	if(low[u]==dfn[u]){
		++cnt;int y;
		do{
			y=stk[top--],instk[y]=0;
			++siz[cnt];
			scc[y]=cnt;
		}while(u!=y);
	}
}
int ind[N],outd[N];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		while(cin>>a,a){
			g[i].push_back(a);
		}
	}
	for(int i=1;i<=n;i++){
		if(!dfn[i]) tarjan(i);
	}
	for(int i=1;i<=n;i++){
		for(auto d:g[i]){
			if(scc[i]!=scc[d]){
				ind[scc[d]]++;
				outd[scc[i]]++;
			}
		}
	}
	int a=0,b=0;
	for(int i=1;i<=cnt;i++){
		if(!ind[i]) a++;
		if(!outd[i]) b++;
	}
	cout<<a<<"\n";
	if(cnt==1) cout<<"0";
	else cout<<max(a,b);
	return 0;
}

