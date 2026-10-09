#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e4+10;
vector<int> g[N];
int a[N],dp[N][2];
void dfs(int s,int fa){
	dp[s][1]=a[s];
	for(auto d:g[s]){
		if(d==fa) continue;
		dfs(d,s);
		dp[s][0]+=dp[d][1];
		dp[s][1]+=min(dp[d][0],dp[d][1]);
	}
	return;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1,0);
	cout<<min(dp[1][0],dp[1][1]);
	return 0;
}

