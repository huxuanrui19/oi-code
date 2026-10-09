#include<bits/stdc++.h>
using namespace std;
int a[int(1e5+5)];
int check(int mid,int n,int m)
{
	for(int i=1;i<=n-m+1;i++)
	{
		if(a[i+m-1]-a[i]<=mid)
		{
			return 1;
		}
	}
	return 0;
}
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int l=0,r=1e9+5,ans=0;
	while(l<r)
	{
		int mid=(l+r)/2;
		if(check(mid,n,m))
		{
			r=mid;
			ans=mid;
		}
		else
		{
			l=mid+1;
		}
	}
	cout<<ans;
	return 0;
}
