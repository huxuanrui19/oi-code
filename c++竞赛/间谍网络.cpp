#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3e3+10;
int n,m,p;
vector<int> g[N];
int tot,dfn[N],low[N];
int top,stk[N],instk[N];
int cnt=0,scc[N],siz[N];
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
	if(dfn[u]==low[u]){
		cnt++;
		int d;
		do{
			d=stk[top--];
			instk[d]=0;
			scc[d]=cnt;
			siz[cnt]++;
		}while(d!=u);
	}
}
struct node{
	int idx,num;
}a[N];
int mi[N],flag[N],din[N],vis[N];
vector<int> gt[N];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n>>p;
	for(int i=1;i<=p;i++) cin>>a[i].idx>>a[i].num;
	cin>>m;
	for(int i=1;i<=m;i++){
		int u,v;cin>>u>>v;
		g[u].push_back(v);
	}
	for(int i=1;i<=n;i++){
		if(!dfn[i]) tarjan(i);
	}
	memset(mi,0x3f,sizeof(mi));
	for(int i=1;i<=p;i++){
		int pos=scc[a[i].idx];
		flag[pos]=1;
		mi[pos]=min(mi[pos],a[i].num);
	}
	for(int i=1;i<=n;i++){
		for(auto d:g[i]){
			if(scc[d]!=scc[i]) din[scc[d]]++,gt[scc[i]].push_back(scc[d]);
		}
	}
	int mark=1,ans=0;
	queue<int> q;
	//for(int i=1;i<=cnt;i++) cout<<mi[i]<<" "<<flag[i];
	for(int i=1;i<=cnt;i++){
		if(din[i]==0){
			if(flag[i]==0) mark=0;
			else{
				ans+=mi[i];q.push(i);
			}
		}
		else if(din[i]!=0){
			if(flag[i]==1) q.push(i);
		}
	}
	if(mark==0){
		cout<<"NO\n";
		while(!q.empty()){
			int u=q.front();q.pop();
			vis[u]=1;
			for(auto v:gt[u]){
				if(!vis[v]) q.push(v);
			}
		}
		for(int i=1;i<=n;i++){
			if(vis[scc[i]]==0){
				cout<<i;break;
			}
		}
	}
	else{
		cout<<"YES\n"<<ans;
	}
	return 0;
}

