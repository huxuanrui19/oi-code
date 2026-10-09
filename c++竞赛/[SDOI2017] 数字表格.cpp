#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10;
const ll mod=1e9+7;
ll fib[N],cnt,mu[N],vis[N],pri[N],fac[N],fibinv[N],facinv[N];
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
    fib[0]=0; fib[1]=1;
    for(int i=2;i<N;i++) {
        fib[i]=(fib[i-1]+fib[i-2])%mod;
    }
    for(int i=1;i<N;i++) {
        fibinv[i]=qp(fib[i],mod-2);
    }
    fill(fac,fac+N,1);
	for(int i=1;i<N;i++){
		for(int j=i;j<N;j+=i){
			ll tmp=j/i;
			if(mu[tmp]==-1) fac[j]=fac[j]*fibinv[i]%mod;
			else if(mu[tmp]==1) fac[j]=fac[j]*fib[i]%mod;
		}
	}
	for(int i=1;i<N;i++) fac[i]=fac[i-1]*fac[i]%mod;
	for(int i=0;i<N;i++) facinv[i]=qp(fac[i],mod-2);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
	int t;
	cin>>t;
	while(t--){
		ll n,m;
		cin>>n>>m;
		if(n>m) swap(n,m);
		ll ans=1;
		for(ll l=1,r;l<=n;l=r+1){
			r=min(n/(n/l),m/(m/l));
			ans=ans*qp((fac[r]*facinv[l-1])%mod,(n/l)*(m/l)%(mod-1))%mod;
		}
		cout<<ans<<"\n";
	}
	return 0;
}

