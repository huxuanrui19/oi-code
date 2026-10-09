#include<bits/stdc++.h>
using namespace std;
int b[10],a[2005][2005],x[4]={0,1,0,-1},y[4]={1,0,-1,0};
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
			b[a[i][j]]++;
		}
	}
	long long res=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			res+=b[a[i][j]];
			for(int k=0;k<4;k++)
			{
				int ii=i+x[k];
				int jj=j+y[k];
				if(a[ii][jj]==a[i][j])
				{
					res--;
				}
			}
			res--;
		}
	}
	cout<<res;
	return 0;
}
