#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,x,y,a,b;
	cin>>n>>x>>y>>a>>b;
	long long maxr=-1,res=0,flag=0,mark=0;
	for(int i=1;i<=n;i++)
	{
		int s,sa,m;
		cin>>s>>sa>>m;
		long long ma=s*x+sa*y;
		if(m>ma)
		{
			res+=m-ma;
			mark=0;
			flag++;
			if(m>2*ma)
			{
				res+=ceil(0.5*(m-ma));
			}
			if(flag>=a)
			{
				res*=2;
			}
		}
		else
		{
			mark++;
			flag=0;
			if(mark>=b)
			{
				res=floor(res/2.0);
			}
		}
		maxr=max(maxr,res);
	}
	cout<<maxr<<" "<<res;
	return 0;
}
