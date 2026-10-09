#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
const ll mod=1e9+7;
ll a[N],b[N],suma[N],sumb[N],sumaa[N],sumbb[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		suma[i]=(suma[i-1]+a[i])%mod;
		sumaa[i]=(sumaa[i-1]+suma[i])%mod;
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
		sumb[i]=(sumb[i-1]+b[i])%mod;
		sumbb[i]=(sumbb[i-1]+sumb[i])%mod;
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		ans=(ans+((i*suma[i])%mod*sumb[i])%mod)%mod;
	}
	for(int i=1;i<=n;i++){
		ans=(ans+(((n-i+1)*suma[i-1])%mod*sumb[i-1])%mod)%mod;
	}
	ll res=0;
	for(int i=1;i<=n;i++){
		res=(res+suma[i-1]*(sumbb[n]-sumbb[i-1]+mod)%mod)%mod;
	}
	for(int i=1;i<=n;i++){
		res=(res+sumb[i-1]*(sumaa[n]-sumaa[i-1]+mod)%mod)%mod;
	}
	cout<<(ans-res+mod)%mod; 
	return 0;
}

