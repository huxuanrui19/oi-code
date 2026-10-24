#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e2+10;
int n,m,e,ans,match[N],vis[N];
vector<int> g[N];
bool dfs(int u){
	for(auto d:g[u]){
		if(vis[d]) continue;
		vis[d]=1;
		if(!match[d]||dfs(match[d])){
			match[d]=u;
			return 1;
		}
	}
	return 0;
}
void hung(){
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		if(dfs(i)) ans++;
	}
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m>>e;
	for(int i=1;i<=e;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
	}
	hung();
	cout<<ans;
	return 0;
}

