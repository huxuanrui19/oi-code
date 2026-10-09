#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=1e5+10,N=15;
ll n,m,k,a[M][N],dp[M][N],sum[M][N];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) cin>>a[j][i];	
	}
	for(int i=1;i<=m;i++){
		sort(a[i]+1,a[i]+n+1,greater<int>());
		for(int j=1;j<=n;j++) sum[i][j]=sum[i][j-1]+a[i][j];
	}
	memset(dp,-1,sizeof(dp));
	dp[1][0]=a[1][1],dp[1][1]=0;
	for(int i=2;i<=m;i++){
		for(int j=0;j<k;j++){
			if(dp[i-1][j]==-1) continue;
			int t=min(1ll*j+(i<=m-k+1),m-i+1);
			for(int p=0;t>=0&&p<=n;t--,p++) dp[i][t]=max(dp[i][t],dp[i-1][j]+sum[i][p]);
		}
	}
	cout<<dp[m][0];
	return 0;
}

