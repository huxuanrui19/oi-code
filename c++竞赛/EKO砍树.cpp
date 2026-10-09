#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,maxn=-1;
ll a[int(1e6+5)];
int check(int mid)
{
	ll sum=0;
	for(int i=1;i<=n;i++)
	{
		sum+=max(0ll,a[i]-mid);
	}
	if(sum>=m)
	{
		return 1;
	}
	return 0;
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	ll l=0,r=maxn,ans;
	while(l<r)
	{
		int mid=(l+r+1)>>1;
		if(check(mid))
		{
			l=mid+1;
			ans=mid; 
		}
		else
		{
			r=mid-1;
		}
	}
	while(check(ans+1))
	{
		ans++;
	}
	cout<<ans;
	return 0;
}
