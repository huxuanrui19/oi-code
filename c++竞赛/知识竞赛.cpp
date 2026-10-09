#include<bits/stdc++.h>
using namespace std;
int a[55][55]={0};
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
		}
	}
	int maxn=-1,k=0;
	for(int j=1;j<=m;j++)
	{
		int sum=0;
		for(int i=1;i<=n;i++)
		{
			sum+=a[i][j];
		}
		if(sum>=maxn)
		{
			maxn=sum;
			k=j;
		}
	}
	maxn=-1;
	for(int i=1;i<=n;i++)
	{
		if(a[i][k]>maxn)
		{
			maxn=a[i][k];
		}
	}
	int res=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i][k]==maxn)
		{
			res++;
		}
	}
	cout<<maxn<<" "<<res;
	return 0;
}
