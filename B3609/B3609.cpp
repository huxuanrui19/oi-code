#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e4+10;
int n,m;vector<int> g[N];

int tot,dfn[N],low[N];
int top,stk[N],instk[N];
int cnt,siz[N],scc[N];
vector<int> sccno[N]; 
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
		++cnt;int y;
		do{
			y=stk[top--];instk[y]=0;
			scc[y]=cnt;siz[cnt]++;
			sccno[cnt].push_back(y);
		}while(u!=y);
	}
}

bool cmp(vector<int> a,vector<int> b){
	return (*a.begin())<(*(b.begin()));
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m;
	for(int i=1,u,v;i<=m;i++){
		cin>>u>>v;
		g[u].push_back(v); 
	}
	for(int i=1;i<=n;i++){
		if(!dfn[i]) tarjan(i);
	}
	
	for(int i=1;i<=cnt;i++) sort(sccno[i].begin(),sccno[i].end());
	sort(sccno+1,sccno+cnt+1,cmp);
	cout<<cnt<<"\n";
	for(int i=1;i<=cnt;i++){
		for(auto d:sccno[i]){
			cout<<d<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
