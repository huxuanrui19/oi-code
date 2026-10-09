#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,a;
	cin>>n>>a;
	ll ans=0;
	for(ll i=max(n-2*a,0ll);i<=min(n,a);i++){
		ll res=n-i;
		ans+=max(min(res,a)-max(res-a,0ll)+1,0ll);
	}
	cout<<ans;
	return 0;
}
