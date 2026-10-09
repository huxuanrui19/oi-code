#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[25][25],flag[25][25];
int main()
{
	int n,m,kx,ky;
	cin>>n>>m>>kx>>ky;
	memset(flag,1,sizeof(flag));
	flag[kx][ky]=0;
	if(kx-2>=0&&ky-1>=0)
	{
		flag[kx-2][ky-1]=0;
	} 
	if(kx-1>=0&&ky-2>=0)
	{
		flag[kx-1][ky-2]=0;
	} 
	if(kx+2<=n&&ky-1>=0)
	{
		flag[kx+2][ky-1]=0;
	} 
	if(kx+1<=n&&ky-2>=0)
	{
		flag[kx+1][ky-2]=0;
	}
	if(ky+1<=m&&kx+2<=n)
	{
		flag[kx+2][ky+1]=0;
	}
	if(ky+2<=m&&kx+1<=n)
	{
		flag[kx+1][ky+2]=0;
	}
	if(ky+1<=m&&kx-2>=0)
	{
		flag[kx-2][ky+1]=0;
	}
	if(ky+2<=m&&kx-1>=0)
	{
		flag[kx-1][ky+2]=0;
	}
	int i=0;
	while(i<=n)
	{
		if(flag[i][0])
		{
			dp[i][0]=1;
		}
		else
		{
			break;
		}
		i++;
	}
	i=0;
	while(i<=m)
	{
		if(flag[0][i])
		{
			dp[0][i]=1;
		}
		else
		{
			break;
		}
		i++;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(flag[i][j])
			{
				dp[i][j]=dp[i-1][j]+dp[i][j-1];
			}
		}
	}
	cout<<dp[n][m];
	return 0;
}
