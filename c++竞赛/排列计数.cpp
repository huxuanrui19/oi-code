#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const int N=1e6+10;
ll fac[N],f[N];
ll qp(ll k,ll n)
{
	ll sum=1;
	while(n>0)
	{
		if(n&1)
		{
			sum=sum*k%mod;
		}
		k=k*k%mod;
		n>>=1;
	}
	return sum;
}
void init(){
	fac[0]=1;
	for(int i=1;i<N;i++){
		fac[i]=fac[i-1]*i%mod;
	}
	f[1]=0;
	f[2]=1;
	for(int i=3;i<N;i++){
		f[i]=(i-1)*(f[i-1]+f[i-2])%mod;
	}
}
ll c(ll n,ll m){
	ll inv1=qp(fac[n-m],mod-2);
	ll inv2=qp(fac[m],mod-2);
	return ((fac[n]*inv1)%mod*inv2)%mod;
}
int main(){
	int t;
	cin>>t;
	init();
	while(t--){
		ll n,m;
		cin>>n>>m;
		if(n==m) cout<<"1"<<endl;
		else if(n-m==1) cout<<"0"<<endl;
		else cout<<(c(n,m)*f[n-m])%mod<<endl;
	}
	return 0;
}
