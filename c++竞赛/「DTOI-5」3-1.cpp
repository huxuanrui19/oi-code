#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
vector<int> g[N];
int hgt=0,dep[N];
void dfs(int u,int fa){
	dep[u]=dep[fa]+1;
	hgt=max(hgt,dep[u]);
	for(auto d:g[u]){
		if(d==fa) continue;
		dfs(d,u);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1,0);
	for(int i=1;i<=n;i++){
		if(i<=hgt){
			cout<<(i-1)<<"\n";
		}
		else cout<<2*(i-hgt)+hgt-1<<"\n";
	}
	return 0;
}

