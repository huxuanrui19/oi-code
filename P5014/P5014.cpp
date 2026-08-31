#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3e6+10;
const ll mod=998244353;
ll fac[N],inv[N],siz[N];
inline ll qp(ll n,ll k){
	ll sum=1;
	while(k){
		if(k&1) sum=sum*n%mod;
		n=n*n%mod;
		k>>=1;
	}
	return sum;
}
inline void init(){
	fac[0]=1;for(ll i=1;i<N;i++) fac[i]=fac[i-1]*i%mod;
	inv[N-1]=qp(fac[N-1],mod-2);for(ll i=N-2;i>=0;i--) inv[i]=inv[i+1]*(i+1)%mod;
	siz[0]=0;for(ll i=1;i<N;i++) siz[i]=siz[i-1]+i;
}
inline ll cob(ll n,ll m){
	if(m>n||n<0||m<0) return 0;
	return fac[n]*inv[m]%mod*inv[n-m]%mod;
}
int main() {
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	init();
	int t;cin>>t;
	while(t--){
		ll u;
      	cin>>u;
		ll num=lower_bound(siz+1,siz+N,u)-siz;
		ll x=num-(siz[num]-u);
    	ll ans=0;
      	num--;x--;
		for(ll i=0;i<=x;i++){
			ll row=num-i,col=x-i;
			ll cat=(cob(row+col,col)-cob(row+col,col-1)+mod)%mod;
			ans=(ans+cat*cob(row+i+col,i)%mod)%mod;
        	//cout<<ans<<" ";
		}
		cout<<ans<<"\n";
	}
	return 0;
}