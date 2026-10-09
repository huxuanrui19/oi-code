#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10;
ll n,m,fac[N],inv_fac[N];
ll qp(ll a,ll k){
	ll sum=1;
	while(k){
		if(k&1) sum=sum*a%m;
		a=a*a%m;
		k>>=1;
	}
	return sum;
}
void init(){
	fac[0]=1;ll t=min(1ll*N-1,m-1);
	for(int i=1;i<=t;i++) fac[i]=fac[i-1]*i%m;
	inv_fac[t]=qp(fac[t],m-2)%m;
	for(int i=t-1;i>=0;i--) inv_fac[i]=inv_fac[i+1]*(i+1)%m;
	return;
}
ll C(ll n,ll x){
	if(x>n) return 0;
	return fac[n]*inv_fac[x]%m*inv_fac[n-x]%m;
}
ll lucas(ll n,ll x){
	if(x==0) return 1;
	return C(n%m,x%m)*lucas(n/m,x/m)%m;
}
ll siz[N<<1],dp[N<<1];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m;
	init();
	for(int i=1;i<=n;i++) siz[i]=1;
	for(int i=n;i>=1;i--) siz[i>>1]+=siz[i];
	for(int i=n+1;i<=2*n+1;i++) dp[i]=1;
	for(int i=n;i>=1;i--){
		dp[i]=lucas(siz[i]-1,siz[i*2])*dp[2*i]%m*dp[2*i+1]%m;
	}
	cout<<dp[1];
	return 0;
}

