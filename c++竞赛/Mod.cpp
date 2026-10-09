#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll a,b,p;
	cin>>a>>b>>p;
	ll mina=a,minb=b;
	if(a==0)
	{
		cout<<a<<(b-(b/p)*p);
	}
	else
	{
		if(b>=p-a)
		{
			b-=p-a;
			b%=p;
			cout<<"0 "<<b;
		}
		else
		{
			cout<<a<<" "<<b;
		}
	}
	return 0;
}
