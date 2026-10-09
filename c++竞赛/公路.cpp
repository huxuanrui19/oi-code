#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int n,d;
	cin>>n>>d;
	ll v[n]={0},a[n+1]={0};
	for(int i=1;i<n;i++)
	{
		cin>>v[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=2;i<=n;i++)
	{
		if(a[i]>a[i-1])
		{
			a[i]=a[i-1];
		}
	}
	ll distmp=0,feetmp=0,fee=0;
	for(int i=1;i<n;i++)
	{
		ll dis=v[i]-distmp;
		if(dis<0)
		{
			distmp=-dis;
			continue;
		}
		feetmp=ceil(dis/double(d));
		distmp=feetmp*d-dis;
		fee+=feetmp*a[i];
	}
	cout<<fee;
	return 0;
}
