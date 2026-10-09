#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=4e3+10;
vector<int> gt[N];
int n,m,vis[N],f[N][N],g[N][4];
void bfs(int x){
	queue<int> q;
	q.push(x);
	f[x][x]=0;
	while(!q.empty()){
		int u=q.front();
		vis[u]=1;
		q.pop();
		for(auto v:gt[u]){
			if(vis[v]) continue;
			q.push(v);
			f[x][v]=f[x][u]+1;
		}
	}
	f[x][0]=-1e9;
	for(int i=1;i<=n;i++){
		if(f[x][i]>f[x][g[x][3]]) g[x][3]=i;
		if(f[x][g[x][3]]>f[x][g[x][2]]) swap(g[x][2],g[x][3]);
		if(f[x][g[x][2]]>f[x][g[x][1]]) swap(g[x][1],g[x][2]);
	}
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		gt[u].push_back(v);
		gt[v].push_back(u);
	}
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		for(int j=1;j<=n;j++) f[i][j]=1e9+10;
		bfs(i);
	}
	int ans=0;
	/*for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) cout<<f[i][j]<<" ";
		cout<<"\n";
	}*/
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=3;k++){
				for(int l=1;l<=3;l++){
					int u=g[i][k],v=g[j][l];
					if(i==u||j==u||i==v||j==v||u==v||i==j) continue;
					ans=max(ans,f[i][u]+f[i][j]+f[j][v]);
				}
			}
		}
	}
	cout<<ans;
	return 0;
}

