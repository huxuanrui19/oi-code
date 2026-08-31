#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=1e6+10;

int id,t,n,m,x,y;
vector<int> g[N];
int col[N];

bool solve(){
	queue<int> q;
	ll vertex_cnt=0,edge_sum=0;
	bool bipartite=true;

	col[x]=1;
	q.push(x);

	while(!q.empty()){
		int u=q.front();
		q.pop();
		vertex_cnt++;
		edge_sum+=g[u].size();

		for(int v:g[u]){
			if(col[v]==0){
				col[v]=-col[u];
				q.push(v);
			}
			else if(col[v]==col[u]){
				bipartite=false;
			}
		}
	}

	if(col[y]==0) return false;
	if(edge_sum/2<vertex_cnt) return false;
	if(bipartite&&col[x]==col[y]) return false;
	return true;
}

void cle(){
	for(int i=1;i<=n;i++){
		g[i].clear();
		col[i]=0;
	}
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
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}

		cout<<(solve()?"Yes":"No")<<'\n';
		cle();
	}
	return 0;
}
