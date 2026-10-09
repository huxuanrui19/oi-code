#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
const ll p=998244353;
ll n,k,a[N],fac[N];
ll fp(ll a,ll b){
	ll sum=1;
	while(b>0){
		if(b&1){
			sum=sum*a%p;
		}
		a=a*a%p;
		b>>=1;
	}
	return sum;
}
void init(){
	fac[0]=1;
	for(int i=1;i<N;i++){
		fac[i]=fac[i-1]*i%p;
	}
	return;
}
ll inve(int n){
	return fp(fac[n],p-2);
}
ll c(int n,int m){
	if(m>n) return 0;
	return (fac[n]*inve(m))%p*inve(n-m)%p;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n>>k;
	ll ans=1,sum=0;
	init();
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) sum+=a[i];
	for(int i=1;i<=n;i++) ans=ans*c(sum,a[i])%p,sum-=a[i];
	cout<<ans;
	return 0;
}

