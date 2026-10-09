#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e3+10;
vector<int> g[N];
int a[N][N],dp1[N],dp2[N],mxd=0;
void dfs(int u,int fa,int dp[]){
	for(auto d:g[u]){
		if(d==fa) continue;
		dfs(d,u,dp);
		mxd=max(mxd,dp[u]+dp[d]+1);
		dp[u]=max(dp[u],dp[d]+1);
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
	for(int u=1;u<=n;u++){
		for(auto d:g[u]){
			memset(dp1,0,sizeof(dp1));
			memset(dp2,0,sizeof(dp2));
			int d1=0,d2=0;
			mxd=0;dfs(u,d,dp1);d1=mxd;
			mxd=0;dfs(d,u,dp2);d2=mxd;
			d1++;d2++;
			if(d1==0||d2==0){
				continue;
			}
			else{
				d1++;d2++;
				a[1][1]++;
				a[d1][d2]++;
				a[d1][1]--;
				a[1][d2]--;
				swap(d1,d2);
				a[1][1]++;
				a[d1][d2]++;
				a[d1][1]--;
				a[1][d2]--;
			}
		}
	}
	int sum=0;
	for(int i=1;i<N;i++){
		for(int j=1;j<N;j++){
			a[i][j]+=a[i][j-1]+a[i-1][j]-a[i-1][j-1];
			if(a[i][j]) sum++;
		}
	}
	cout<<sum;
	return 0;
}
