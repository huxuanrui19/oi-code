#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf=0x7f7f7f7f;
const ll mod=1e9+7;
const int N=5e6+10;
ll mu[N],vis[N],pri[N];
unordered_map<ll,ll> summu;
void init()
{
	vis[0]=vis[1]=1;
    mu[1]=1;
    int cnt=0;
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
            mu[i*pri[j]]=-mu[i];
        }
    }
    for(int i=1;i<N;i++){
        mu[i]+=mu[i-1];
    }
}
ll getsmu(ll x){
	if(x<N){
		return mu[x];
	}
	else if(summu[x]){
		return summu[x];
	}
	ll ans=1;
	for(ll l=2,r;l<=x;l=r+1){
		r=x/(x/l);
		ans-=(r-l+1)*getsmu(x/l);
	}
	summu[x]=ans;
	return ans;
}
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
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,k,l,r;
	cin>>n>>k>>l>>r; 
	l=(l-1)/k;
	r=r/k;
	ll ans=0;
	init();
	for(int i=1,j;i<=r;i=j+1){
		j=min(l/i?l/(l/i):inf,r/(r/i));
		ans=(ans+(1ll*(getsmu(j)-getsmu(i-1))*qp(r/i-l/i,n))%mod)%mod;
	}
	cout<<(ans+mod)%mod;
	return 0;
}

