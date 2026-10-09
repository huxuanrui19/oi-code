#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a,b,w,h;
int check(ll d)
{
	ll _a=a+2*d;
	ll _b=b+2*d;
	ll _n=max((w/_a)*(h/_b),(w/_b)*(h/_a));
	return _n>=n;
}
int main()
{
	cin>>n>>a>>b>>w>>h;
	ll l=0,r=min(w,h)/2,ans=0;
	while(l<r)
	{
		ll mid=(l+r+1)>>1;
		//cout<<mid<<" "<<check(mid)<<endl;
		if(check(mid))
		{
			l=mid;
			ans=max(ans,mid);
		}
		else
		{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}
