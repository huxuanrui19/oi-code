#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
ll fac[N];
ll a,b,p;
ll quickpow(ll k,ll n)
{
	ll sum=1;
	while(n>0)
	{
		if(n&1)
		{
			sum=sum*k%p;
		}
		k=k*k%p;
		n>>=1;
	}
	return sum;
}
ll inve(ll n){
	return quickpow(fac[n],p-2);
}
ll c(int n,int m){
	if(m>n){
		return 0;
	}
	return (fac[n]*inve(m)%p*inve(n-m))%p;
}
ll lucas(ll n,ll m){
	if(m==0){
		return 1;
	}
	return c(n%p,m%p)*lucas(n/p,m/p)%p;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>a>>b>>p;
		fac[0]=1;
		for(int i=1;i<=p;i++){
			fac[i]=(fac[i-1]*i)%p;
		}
		cout<<lucas(a+b,a)<<endl;
	}
	return 0;
}
