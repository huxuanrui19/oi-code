#include<bits/stdc++.h>
using namespace std;
int a[int(2e5+5)],b[int(2e5+5)];
int main()
{
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	b[1]=1;
	int maxn=a[1]+k,minn=a[1]-k;
	for(int i=2;i<=n;i++)
	{
		if(a[i]<=maxn&&a[i]>=minn)
		{
			b[i]=1;
			maxn=max(maxn,a[i]+k);
			minn=min(minn,a[i]-k);
		}
		else
		{
			b[i]=0;
		}
	}
	for(int i=1;i<=n;i++)
	{
		cout<<b[i]<<" ";
	}
	return 0;
}
