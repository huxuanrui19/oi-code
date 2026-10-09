#include<bits/stdc++.h>
using namespace std;
int a[int(1e5+10)],dp[int(1e5+10)][2];
vector<int> G[int(1e5+10)];
void dfs(int s){
	if(G[s].size()==0){
		dp[s][0]=0;
		dp[s][1]=a[s];
		return;
	}
	for(int i=0;i<G[s].size();i++){
		dfs(G[s][i]);
		dp[s][0]+=max(dp[G[s][i]][1],dp[G[s][i]][0]);
		dp[s][1]+=dp[G[s][i]][0];
	}
	dp[s][1]+=a[s];
	return;
}
int main(){
	int n;
	cin>>n;
	int fa=0;
	for(int i=1;i<=n;i++){
		int u,v,w;
		cin>>u>>v>>w;
		if(u==0){
			fa=v;
		}
		G[u].push_back(v);
		a[v]=w;
	}
	dfs(fa);
	cout<<max(dp[fa][0],dp[fa][1]);
	return 0;
} 
