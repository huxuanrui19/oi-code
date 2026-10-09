#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
vector<int> g[N];
vector<int> gt[N];
ll maxn,w[N],flag[N],vis[N][2],dp[N][2],mxw[N];
ll id,ver[N];

struct node{
	int dis,type,idx;
};
bool operator < (node a, node b) {
	return b.dis < a.dis;
}
priority_queue<node,vector<node>>q;

void dfs(int u,int fa){
	if(flag[u]) return;
	flag[u]=1;
	maxn=max(maxn,w[u]);
	ver[++id]=u;
	for(auto d:g[u]) if(u!=fa) dfs(d,u);
	for(auto d:gt[u]) if(u!=fa) dfs(d,u);
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;
	//read(n);read(m);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>w[i];
	}
	
	for(int i=1;i<=m;i++){
		int u,v;
		//read(u);read(v);
		cin>>u>>v;
		if(u==v) continue;
		g[u].push_back(v);
		gt[v].push_back(u);
	}
	
	for(int i=1;i<=n;i++){
		maxn=id=0;
		if(!flag[i]) dfs(i,0);
		for(int j=1;j<=id;j++) mxw[ver[j]]=maxn;
	}
	
	memset(dp,0x3f,sizeof(dp));
	for(int i=1;i<=n;i++){
		if(mxw[i]==w[i]){
			dp[i][0]=dp[i][1]=0;
			q.push((node){dp[i][0],0,i});
			q.push((node){dp[i][1],1,i});
		}
	}
	
	while(!q.empty()){
		int cnt=q.top().dis,u=q.top().idx,type=q.top().type;
		q.pop();
		if(vis[u][type]) continue;
		vis[u][type]=1;
		if(type==0){
			for(auto d:g[u]){
				if(dp[d][0]>=cnt){
					dp[d][0]=cnt;
					q.push((node){dp[d][0],0,d});
				}
			}
			for(auto d:gt[u]){
				if(dp[d][1]>=cnt+1){
					dp[d][1]=cnt+1;
					q.push((node){dp[d][1],1,d});
				}
			}
		}
		else{
			for(auto d:g[u]){
				if(dp[d][0]>=cnt+1){
					dp[d][0]=cnt+1;
					q.push((node){dp[d][0],0,d});
				}
			}
			for(auto d:gt[u]){
				if(dp[d][1]>=cnt){
					dp[d][1]=cnt;
					q.push((node){dp[d][1],1,d});
				}
			}
		}
	}
	
	for(int i=1;i<=n;i++) cout<<(min(dp[i][0],dp[i][1])+(mxw[i]==w[i])^1)<<" ";
	return 0;
}
