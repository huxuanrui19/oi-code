#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b)
{
	if(a<b)
	{
		swap(a,b);
	}
	if(a%b==0)
	{
		return b;
	}
	return gcd(b,a%b);
}
int main()
{
	string n;
	cin>>n;
	ll m=0,k=1;
	for(int i=2;i<n.size();i++)
	{
		m+=10*(n[i]-'0');
		m*=10;
		k*=10;
	}
	k*=100;
	ll p=k-m;
	ll t;
	while((t=__gcd(p,m))!=1)
	{
		p/=t;
		m/=t;
	}
	for(int i=1;i<=5;i++)
	{
		if(i==(n[0]-'0'))
		{
			cout<<p<<" ";
		}
		else if(i==(n[0]-'0'+1))
		{
			cout<<m<<" ";
		}
		else
		{
			cout<<"0 ";
		}
	}
	return 0;
}
