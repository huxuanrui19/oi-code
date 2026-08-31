#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10;
int id,t,n,m,x,y;
vector<int> g[N];
int deg,siz,flag,col[N];
void dfs2(int x,int c){
	siz++;
	deg+=g[x].size();
	col[x]=c;
	for(auto d:g[x]){
		if(col[d]==0) dfs2(d,-c);
		else if(col[d]==c) flag=0;
	}
}
void cle(){
	for(int i=1;i<=n;i++) g[i].clear();
	memset(col,0,sizeof(col));
    deg=siz=0;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>id>>t;
	while(t--){
		cin>>n>>m>>x>>y;
		for(int i=1;i<=m;i++){
			int u,v;cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		flag=1;dfs2(x,1);deg/=2;
		if(col[y]==0) cout<<"No\n";
		else if(deg<siz) cout<<"No\n";
		else if(flag&&col[x]==col[y]) cout<<"No\n";
		else cout<<"Yes\n";
		cle();
	}
	return 0;
}