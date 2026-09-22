#include<bits/stdc++.h>
#define ll long long 
#define maxn 205
using namespace std;
ll dp[maxn][maxn][205];
int n,k;
ll a[maxn],b[maxn];
ll dfs(int l,int r,int k)
{
	if (dp[l][r][k]!=-1) return dp[l][r][k];
	if (l==r) return dp[l][r][k]=0; //区间长度为0，不用走了 
	if (k==1) return dp[l][r][k]=dfs(l,r-1,k)+a[r]*(r-l);
	if (k>=r-l+1) //层数>=r-l的情况，每个数字都可以一步到位 
	{
		return dp[l][r][k]=b[r]-b[l];
	} 
	ll ret=1ll<<60;
	//枚举这一层第一个放在哪，显然是l+k开始的 
	for (int i=l+k;i<=r;i++) 
	{
		ret=min(ret,dfs(l,i-1,k-1)+dfs(i,r,k)+(b[r]-b[i-1]));
	}
	return dp[l][r][k]=ret;
}
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout); 
	cin>>n>>k;
	for (int i=1;i<=n;i++) {cin>>a[i]; b[i]=a[i]+b[i-1];}
	memset(dp,-1,sizeof(dp));
	dfs(0,n,k);
	cout<<dp[0][n][k]<<endl;
}
