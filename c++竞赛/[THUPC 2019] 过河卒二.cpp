#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll p=59393;
const int N=1e5+10,M=25;
ll n,m,k,fac[N],inv[N],dp[M][M];
struct node{
	int xi,yi;
	bool operator <(const node &tmp) const{
		if(xi!=tmp.xi) return xi<tmp.xi;
		return yi<tmp.yi;
	}
}a[M];
ll qp(ll a,ll k){
	ll sum=1;
	while(k){
		if(k&1) sum=sum*a%p;
		a=a*a%p;
		k>>=1;
	}
	return sum;
}
void init(){
	fac[0]=1;
	for(int i=1;i<N;i++) fac[i]=fac[i-1]*i%p;
	inv[p-1]=qp(fac[p-1],p-2);
	for(int i=p-2;i>=0;i--) inv[i]=inv[i+1]*(i+1)%p;
}
ll c(ll n,ll m){
	if(m>n) return 0;
	return fac[n]*inv[m]%p*inv[n-m]%p;
}
ll lucas(ll n,ll m){
	if(m==0) return 1;
	return c(n%p,m%p)*lucas(n/p,m/p)%p; 
}
ll cal(ll n,ll m){
	if(n>m) swap(n,m);
	ll ans=0;
	for(int i=0;i<=n;i++){
		ans=(ans+lucas(n+m-i,i)*lucas(n+m-2*i,n-i)%p)%p;
	}
	return ans;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	init();
	cin>>n>>m>>k;
	for(int i=1;i<=k;i++) cin>>a[i].xi>>a[i].yi;
	sort(a+1,a+k+1);
	a[0].xi=a[0].yi=1;k++;a[k].xi=n+1,a[k].yi=m+1;
	for(int i=0;i<=k;i++){
		for(int j=i+1;j<=k;j++){
			if(a[i].xi>a[j].xi||a[i].yi>a[j].yi) continue;
			dp[i][j]=cal(a[j].xi-a[i].xi,a[j].yi-a[i].yi);
		}
	}
	ll ans=cal(n,m);
	for(int i=1;i<(1<<(k-1));i++){
		ll cnt=1,num=0,last=0;
		for(int j=1;j<k;j++){
			if(i&(1<<(j-1))){
				num++;
				cnt=cnt*dp[last][j]%p;
				last=j;
			}
		}
		cnt=cnt*dp[last][k]%p;
		if(num%2==0) ans=(ans+cnt)%p;
		else ans=((ans-cnt)%p+p)%p;
	}
	cout<<ans;
	return 0;
}
