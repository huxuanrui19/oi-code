#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10,M=2e2+10;
int n,m,a[N],sum[N],dp[M][M];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++) sum[i]=sum[i-1]^a[i];
		for(int i=0;i<M;i++){
			for(int j=0;j<M;j++) dp[i][j]=0;
		}
		dp[0][0]=(1<<30)-1+(1<<30);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(j>i) continue;
				for(int k=0;k<i;k++){
					dp[i][j]=max(dp[k][j-1]&(sum[i]^sum[k]),dp[i][j]);
				}
			}
		}
		
		cout<<dp[n][m]<<"\n";
	}
	return 0;
}

