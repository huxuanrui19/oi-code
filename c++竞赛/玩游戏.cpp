#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
set<int> g[N];
int tot,deg[N],pre[N],nxt[N],vis[N];
struct node{
	int x,l,r;
};
void output(int x){
	cout<<x<<" ";
	vis[x]=1;
	int r=nxt[x];
	int l=pre[x];
	if(l>r) swap(l,r);
	if(!vis[l]) output(l);
	if(!vis[r]) output(r);
	return;
} 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		if(u==v) continue;
		g[u].insert(v);
		g[v].insert(u);
	}
	queue<int> q;
	for(int i=1;i<=n;i++){
		deg[i]=g[i].size();
		if(deg[i]==2) q.push(i);
	}
	stack<node> st;
	tot=n;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		if(g[u].size()!=2) continue;
		int nowl=*g[u].begin();
		g[u].erase(g[u].begin());
		int nowr=*g[u].begin();
		g[u].erase(g[u].begin());
		--tot;
		st.push({u,nowl,nowr});
		g[nowl].erase(u);
		g[nowr].erase(u);
		deg[nowl]--;
		deg[nowr]--;
		g[u].clear();
		deg[u]=0;
		if(g[nowl].find(nowr)==g[nowl].end()){
			g[nowl].insert(nowr);
			g[nowr].insert(nowl);
			deg[nowl]++;
			deg[nowr]++;
		}
		if(deg[nowl]==2) q.push(nowl);
		if(deg[nowr]==2) q.push(nowr);
	}
	int u=-1,v=-1;
	for(int i=1;i<=n;i++){
		if(deg[i]>0){
			if(u==-1) u=i;
			else v=i;
		}
	}
	nxt[u]=v;
	pre[v]=u;
	nxt[v]=u;
	pre[u]=v;
	while(!st.empty()){
		int now=st.top().x;
		int nowl=st.top().l;
		int nowr=st.top().r;
		if(nxt[nowr]==nowl){
			swap(nowr,nowl);
		}
		nxt[nowl]=now;
		pre[nowr]=now;
		nxt[now]=nowr;
		pre[now]=nowl;
		st.pop();
	}
	output(1);
	return 0;
}

