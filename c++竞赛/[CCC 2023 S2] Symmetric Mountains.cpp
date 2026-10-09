#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e3+10;
int h[N],dp[N][N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>h[i];
	}
	memset(dp,0x3f,sizeof(dp));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			dp[i][j]=0;
		}
	}
	for(int i=1;i<=n;i++){
		for(int l=1;l+i-1<=n;l++){
			dp[l][l+i-1]=min(dp[l+1][l+i-2]+abs(h[l]-h[l+i-1]),dp[l][l+i-1]);
		}
		int minn=0x3f3f3f3f;
		for(int l=1;l+i-1<=n;l++){
			minn=min(minn,dp[l][l+i-1]);
		}
		cout<<minn<<" ";
	}
	return 0;
}

