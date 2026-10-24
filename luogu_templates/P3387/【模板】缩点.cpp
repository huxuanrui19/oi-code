#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e4+10;
vector<int> g[N];
vector<int> gt[N];
int tot,dfn[N],low[N];
int top,stk[N],instk[N];
int cnt,siz[N],scc[N];
void tarjan(int u){
	dfn[u]=low[u]=++tot;
	stk[++top]=u,instk[u]=1;
	
	for(auto v:g[u]){
		if(!dfn[v]){
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else if(instk[v]) low[u]=min(low[u],dfn[v]);
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

int n,m,a[N],dp[N],ind[N],scca[N];
struct node{
	int r,no;
	bool operator <(const node &x)const{
		return r>x.r;
	}
}rk[N];
void topo(){
	queue<int> q;
	for(int i=1;i<=cnt;i++){
		if(ind[i]==0) q.push(i);
	}
	int num=0;
	while(!q.empty()){
		int u=q.front();
		num++;
		rk[num]=node{num,u};
		q.pop();
		for(auto v:gt[u]){
			ind[v]--;
			if(ind[v]==0) q.push(v);
		}
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
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
	}
	for(int i=1;i<=n;i++){
		if(!dfn[i]) tarjan(i);
	}
	for(int i=1;i<=n;i++){
		for(auto j:g[i]){
			if(scc[i]!=scc[j]) gt[scc[i]].push_back(scc[j]),ind[scc[j]]++;
		}
	}
	for(int i=1;i<=n;i++){
		scca[scc[i]]+=a[i];
	}
	topo();
	sort(rk+1,rk+cnt+1);
	int ans=0;
	for(int i=1;i<=cnt;i++){
		int u=rk[i].no;
		dp[u]=scca[u];
		for(auto j:gt[u]){
			dp[u]=max(dp[u],dp[j]+scca[u]);
		}
		ans=max(ans,dp[u]); 
	}
	cout<<ans;
	return 0;
}
