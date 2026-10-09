#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
const int N=100+10;
int n,k,d,s,dp[N][N];
pii arr[N];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n>>k>>d>>s;
	for(int i=1;i<=k;i++){
		cin>>arr[i].first>>arr[i].second;
	}
	sort(arr+1,arr+k+1);
	memset(dp,0x3f,sizeof(dp));
	dp[0][0]=0;
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			dp[i][j]=dp[i-1][j];
			for(int l=0;l<=min(j,arr[i].second);l++){
				dp[i][j]=min(dp[i-1][j-l]+l*arr[i].first+d,dp[i][j]);
			}
		}
	}
	if(dp[k][n]<0x3f3f3f3f) cout<<dp[k][n];
	else cout<<"impossible";
	return 0;
}
