#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[int(1e5+5)];
int main()
{
	ll n;
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	ll sum,res=0;
	cin>>sum;
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++)
	{
		ll tar=sum-a[i];
		ll ind=lower_bound(a+1,a+n+1,tar)-a;
		if(tar==a[ind]&&ind!=i)
		{
			res++;
			cout<<a[i]<<" "<<tar;
			return 0;
		}
	}
	if(!res)
	{
		cout<<"No";
	}
	return 0;
}
