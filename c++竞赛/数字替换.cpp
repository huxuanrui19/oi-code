#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,k,maxn=-1e9-7,minn=1e9+7;
	cin>>n>>k;
	int a[n+1];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		minn=min(minn,a[i]);
		maxn=max(maxn,a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]<k)
		{
			cout<<minn<<" ";
		}
		else if(a[i]>k)
		{
			cout<<maxn<<" ";
		}
		else
		{
			cout<<k<<" ";
		}
	}
	return 0;
}
