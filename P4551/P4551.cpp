#include<bits/stdc++.h>
#define pii pair<int,ll>
using namespace std;
typedef long long ll;
const int N=1e5+10;
int n,tot,dis[N],tree[N*35][2];
vector<pii> g[N];
void insert(int num){
	int p=0;
	for(int i=30;i>=0;i--){
		int cnt=(num>>i)&1;
		if(tree[p][cnt]==0) tree[p][cnt]=++tot;
		p=tree[p][cnt];
	}
	return;
}
int query(int num){
	int p=0,ans=0; 
	for(int i=30;i>=0;i--){
		int cnt=(num>>i)&1;
		if(tree[p][1^cnt]){
			ans|=(1<<i);
			p=tree[p][1^cnt];
		}
		else p=tree[p][cnt];
	}
	return ans;
}
void dfs(int u,int fa,int val){
	dis[u]=dis[fa]^val;
	for(auto d:g[u]){
		if(d.first==fa) continue;
		dfs(d.first,u,d.second);
	}
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	for(int i=1,u,v,w;i<n;i++){
		cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	dfs(1,0,0);int ans=0;
	for(int i=1;i<=n;i++) insert(dis[i]);
	for(int i=1;i<=n;i++) ans=max(ans,query(dis[i]));
	cout<<ans;
	return 0;
}
