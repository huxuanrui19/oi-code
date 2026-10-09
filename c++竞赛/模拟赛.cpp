#include<bits/stdc++.h>
using namespace std;
int a[1005][1005],b[1005][1005];
int main()
{
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
			b[a[i][j]][j]++;
		}
	}
	for(int i=1;i<=k;i++)
	{
		int sum=0;
		for(int j=1;j<=m;j++)
		{
			if(b[i][j])
			{
				sum++;
			}
		}
		cout<<sum<<" ";
	}
	return 0;
}
