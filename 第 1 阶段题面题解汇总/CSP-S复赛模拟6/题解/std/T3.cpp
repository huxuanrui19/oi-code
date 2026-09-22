#include<bits/stdc++.h>
#define ll long long 
#define maxn 525
#define mod 998244353
#define mid 255
using namespace std;
ll dp[2][2][maxn][maxn],fac[maxn]; //当前分差，当前交换次数，该谁了 
ll ans[maxn]; //一共n个元素的俩有序数列排序，交换次数<=k的方案 
void add(ll &x,ll y) {x=(x+y)%mod; return;}
int n,k;
void init()
{
	fac[0]=1; for (int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
	int now=0,nxt=1;
	dp[0][0][mid+1][0]=1; dp[0][1][mid-1][0]=1; //从-1或者+1开始
	for (int i=1;i<=n;i++)
	{
		int tt=min(i,250);
		for (int t=0;t<=1;t++)
		for (int cha=mid-tt;cha<=mid+tt;cha++)
		for (int huan=0;huan<=min(i-1,k);huan++) //最多能换这么多次
		if (dp[now][t][cha][huan])
		{
//			cout<<i<<" "<<t<<" "<<cha<<" "<<huan<<" "<<dp[now][t][cha][huan]<<endl;
			//第一种，不换
			add(dp[nxt][t][cha+(t==0?1:-1)][huan],dp[now][t][cha][huan]);
			//第二种，换
			add(dp[nxt][1-t][cha+(t==0?-1:1)][huan+1],dp[now][t][cha][huan]);
			if ((i&1)&&cha==mid+1) //奇数，则左边比右边多一个 
			{
				add(ans[i],dp[now][t][cha][huan]);
			}
			if ((i&1)==0 && cha==mid+0) //偶数，则左右一样多
			{
				add(ans[i],dp[now][t][cha][huan]);
			}
			dp[now][t][cha][huan]=0; //清空一下 
		}
		swap(now,nxt);
	}
}
ll ret=1;
void work(int n)
{
	if (n<=k) 
	{
		ret=ret*fac[n]%mod;
		return;
	}
	int rig=n/2,lef=n-rig;
	work(lef); work(rig);
	ret=ret*ans[n]%mod;
}

int main()
{
	freopen("merge.in","r",stdin);
	freopen("merge.out","w",stdout);
	cin>>n>>k;
	init();
	work(n);
//	for (int i=1;i<=n;i++) cout<<ans[i]<<" "; cout<<endl;
	cout<<ret<<endl;
}
