#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e2+5;
int n,m,a[N],vis[N];
vector<int> g[N];
int dfs(int u,int f,int len,int dis){
	if(len>dis) return 0;
	int ans=0;
	if(a[u]) ans++;
	for(auto d:g[u]){
		if(vis[d]==0||d==f) continue;
		ans+=dfs(d,u,len+1,dis);
	}
	return ans;
}
bool check(int dis){
	queue<int> q;
	memset(vis,0,sizeof(vis));
	q.push(1);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		int ans=0;
		if(a[u]){
			ans=dfs(u,0,0,dis);
		}
		if(ans>=m) return true;
		for(auto d:g[u]){
			if(!vis[d]) q.push(d);
		}
	}
	return false;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int l=0,r=n-1,ans=0;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)){
			r=mid-1;
			ans=mid;
		}
		else l=mid+1;
	}
	cout<<ans;
	return 0;
}

