#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll a,b,c,m;
	cin>>a>>b>>c>>m;
	ll v=a*b*c,x=0,y=0,z=0;
	for(int i=1;i<=m;i++)
	{
		ll op,k;
		cin>>op>>k;
		if(op==1)
		{
			x=max(x,k);
		}
		else if(op==2)
		{
			y=max(y,k);
		}
		else
		{
			z=max(z,k);
		}
		v=(a-x)*(b-y)*(c-z);
		cout<<v<<endl;
	}
	return 0;
}
