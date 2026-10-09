#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e7+10;
const ll mod=20101009,inv2=10050505;
ll cnt,mu[N],vis[N],pri[N],sum[N];
void init()
{
    mu[1]=1;
    for(int i=2;i<N;i++){
        if(vis[i]==0){
            mu[i]=-1;
            vis[i]=1;
            pri[++cnt]=i;
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
            mu[i*pri[j]]=mu[i]*mu[pri[j]];
        }
    }
    sum[1]=mu[1]*1*1;
    for(int i=2;i<N;i++){
    	sum[i]=sum[i-1]+mu[i]*i*i%mod;
	}
}
ll f(ll n){
	return ((n*(n+1))%mod*inv2)%mod;
}
ll ca(ll n,ll m){
	if(n>m) swap(n,m);
	ll ans=0;
	for(ll l=1,r;l<=n;l=r+1){
		r=min(n/(n/l),m/(m/l));
		ans=(ans+((sum[r]-sum[l-1]+mod)%mod*f(n/l))%mod*f(m/l)%mod)%mod; 
	}
	return ans;
}
ll cal2(ll n,ll m){
	if(n>m) swap(n,m);
	ll ans=0;
	for(ll l=1,r;l<=n;l=r+1){
		r=min(n/(n/l),m/(m/l));
		ans=(ans+((f(r)-f(l-1)+mod)%mod*ca(n/l,m/l))%mod)%mod; 
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
	init();
	cout<<cal2(n,m);
	return 0;
}

