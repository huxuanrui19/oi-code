#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
int n,a[N],dp[N][20][2];
void init(){
	for(int i=1;i<=n;i++){
		dp[i][0][0]=a[i];
		dp[i][0][1]=a[i];
	}
	for(int i=1;i<=log2(n);i++){
		for(int j=1;j+(1<<i)-1<=n;j++){
			dp[j][i][0]=max(dp[j][i-1][0],dp[j+(1<<(i-1))][i-1][0]);
			dp[j][i][1]=min(dp[j][i-1][1],dp[j+(1<<(i-1))][i-1][1]);
		}
	}
}
int query(int l,int r){
	int p=log2(r-l+1);
	return (min(dp[l][p][1],dp[r-(1<<p)+1][p][1]))^(max(dp[l][p][0],dp[r-(1<<p)+1][p][0]));
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	freopen("perfect.in","r",stdin);
	freopen("prefect.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	init();
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			ans=max(ans,query(i,j));
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

