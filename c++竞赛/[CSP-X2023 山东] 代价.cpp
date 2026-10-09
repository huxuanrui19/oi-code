#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
ll n;
ll a,b,arr[N],sum[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>a>>b;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	sort(arr+1,arr+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+arr[i];
	}
	ll ans=1e18;
	for(ll i=1;i<=n;i++){
		ll cnt=(arr[i]*i-sum[i])*a+(sum[n]-sum[i]-arr[i]*(n-i))*b;
		ans=min(ans,cnt);
	}
	cout<<ans;
	return 0;
}
