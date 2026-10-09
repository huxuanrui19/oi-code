#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3e6+10;
const ll mod=998244353;
int cnt=0,mu[N],vis[N],pri[N];
map<int,int> summu;
void init(){
	mu[1]=vis[1]=1;
	for(int i=2;i<N;i++){
		if(!vis[i]){
			pri[++cnt]=i;
			vis[i]=1;
			mu[i]=-1;
		}
		for(int j=1;j<=cnt;j++){
			if(i*pri[j]>=N){
				break;
			}
			vis[i*pri[j]]=1;
			if(i%pri[j]==0){
				mu[i*pri[j]]=0;
				break;
			}
			mu[i*pri[j]]=-mu[i];
		}
	}
	for(int i=1;i<N;i++){
		mu[i]=mu[i-1]+mu[i];
	}
}
ll fp(ll a,ll p){
	ll s=1;
	while(p){
		if(p&1) s=s*a%mod;
		a=a*a%mod;
		p>>=1;
	}
	return s;
}
ll getsmu(ll n){
	if(n<N){
		return mu[n];
	}
	if(summu.count(n)!=false){
		return summu[n];
	}
	ll ans=1;
	for(ll l=2,r;l<=n;l=r+1){
		r=n/(n/l);
		ans=(ans-(long long)(r-l+1)*getsmu(n/l)+mod)%mod;
	}
	summu[n]=ans;
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n;
	cin>>n;
	ll ans=0;
	init();
	for(ll l=1,r;l<=n;l=r+1){
		r=n/(n/l);
		ans=(ans+(getsmu(r)-getsmu(l-1)+mod)%mod*fp(n/l,3)%mod+mod)%mod;
	}
	cout<<ans;
	return 0;
}

