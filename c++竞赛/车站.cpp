#include<bits/stdc++.h>
using namespace std;
long long fib[25],sum[25];
int main()
{
	int a,n,m,x;
	cin>>a>>n>>m>>x;
	fib[1]=1;
	fib[2]=1;
	for(int i=3;i<=24;i++)
	{
		fib[i]=fib[i-1]+fib[i-2];
	}
	int ans=a;
	if(x>=3)
	{
		ans+=a;
	}
	if(x<=3)
	{
		cout<<ans;
		return 0;
	}
	if(x>=4)
	{
		for(int i=1;i<=n-4;i++)
		{
			sum[i]=sum[i-1]+fib[i]; //求前缀和 
		}
		int b=(m-ans-sum[n-5]*a)/sum[n-4]; //还有ans,导致一直WA 
		ans+=a*sum[x-4]+b*sum[x-3];
	}
	cout<<ans; 
	return 0;
}
