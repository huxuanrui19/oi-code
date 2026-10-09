#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int x,y,k;
	cin>>x>>y>>k;
	int maxn=-1;
	for(int i=0;i<=x;i++)
	{
		for(int j=1;j<=y;j++)
		{
			for(int kk=0;kk<=k;kk++)
			{
				maxn=max(maxn,(i+j)^kk);
			}
		}
	}
	int cnt=0;
	for(int i=0;i<=x;i++)
	{
		for(int j=1;j<=y;j++)
		{
			for(int kk=0;kk<=k;kk++)
			{
				if(maxn==((i+j)^kk))
				{
					cnt++;
				}
			}
		}
	}
	cout<<maxn<<endl<<cnt;
	return 0;
}
