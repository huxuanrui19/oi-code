#include<bits/stdc++.h>
using namespace std;
int a[10],sum[105];
int main()
{
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=0;i<=k;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			int sum=0;
			for(int kk=0;kk<=k;kk++)
			{
				sum+=a[kk]*pow(j,kk);
			}
			if(sum==n-i-1)
			{
				cout<<"*";
			}
			else
			{
				cout<<".";
			}
		}
		cout<<endl;
	}
	return 0;
}
