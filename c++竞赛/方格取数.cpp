#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[15][15],dp[15][15][15][15];
int main()
{
	int n;
	cin>>n;
	ll x,y,num;
	cin>>x>>y>>num;
	while((x||y)||num){
		a[x][y]=num;
		cin>>x>>y>>num;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				for(int l=1;l<=n;l++){
					if((i!=k)||(j!=l))	dp[i][j][k][l]=max(max(dp[i-1][j][k-1][l],dp[i-1][j][k][l-1]),max(dp[i][j-1][k-1][l],dp[i][j-1][k][l-1]))+a[i][j]+a[k][l];
					else	dp[i][j][k][l]=max(max(dp[i-1][j][k-1][l],dp[i-1][j][k][l-1]),max(dp[i][j-1][k-1][l],dp[i][j-1][k][l-1]))+a[i][j];
				}
			}
		}
	}
	cout<<dp[n][n][n][n];
	return 0;
}
