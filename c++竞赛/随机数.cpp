#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll n,l,r;
	cin>>n>>l>>r;
	double amin=l/n;
	double amax=r/n;
	int _a=ceil(amin);
	int _a1=int(amax);
	for(int i=_a;i<=_a1;i++)
	{	
		if(i*n<=r&&i*n>=l)
		{
			for(int j=1;j<=n;j++)
			{
				cout<<i<<" ";
				return 0;
			}
		}
	}
	return 0;
}
