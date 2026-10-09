#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=19940417,inv6=3323403,inv2=9970209;
ll sum(ll n){
	return (n*(n+1))%mod*inv2%mod;
}
ll kkk(ll n){
	ll ans=n*n%mod;
	for(ll l=1,r=0;l<=n;l=r+1){
		r=n/(n/l);
		ans=(ans-(n/l)*(sum(r)-sum(l-1))%mod)%mod;
	}
	return (ans+mod)%mod;
}
ll sum2(ll n){
	return ((n*(n+1))%mod*(2*n+1))%mod*inv6%mod;
}
ll sc03(ll n,ll m){
	ll ans=0;
	for(int l=1,r=0;l<=n;l=r+1){
		r=min(n/(n/l),m/(m/l));
		ll a=n*m%mod*(r-l+1)%mod;
		ll b=((sum(r)-sum(l-1)+mod)%mod*((n/l)*m%mod+(m/l)*n%mod)%mod)%mod;
		ll c=((sum2(r)-sum2(l-1)+mod)%mod*(n/l)%mod)%mod*(m/l)%mod;
		ans=(ans+a+c-b+mod)%mod;
	}
	return ans;
} 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,m;
	cin>>n>>m;
	if(n>m) swap(n,m);
	cout<<(kkk(n)*kkk(m)%mod-sc03(n,m)%mod+mod)%mod;
	return 0;
}

