#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll p,n,inv6,inv2;
ll fp(ll k,ll x)
{
	ll sum=1;
	while(x)
	{
		if(x&1)
		{
			sum=sum*k%p;
		}
		k=k*k%p;
		x>>=1;
	}
	return sum;
}//快速幂 
const int N=5e6+10;
ll phi[N+1],vis[N+1],pri[N+1],sum[N+1];
void init()
{
    phi[1]=1;
    int cnt=0;
    for(ll i=2;i<N;i++){
        if(vis[i]==0){
            phi[i]=i-1;
            vis[i]=1;
            pri[++cnt]=i;
        }
        for(ll j=1;j<=cnt;j++){
            if(i*pri[j]>=N){
                break;
            }
            vis[i*pri[j]]=1;
            if(i%pri[j]==0){
                phi[i*pri[j]]=(phi[i]*pri[j])%p;
                break;
            }
            phi[i*pri[j]]=(phi[i]*phi[pri[j]])%p;
        }
    }
    sum[1]=1*1*phi[1];
    for(ll i=2;i<N;i++){
        sum[i]=(sum[i-1]+((i*i)%p*phi[i])%p)%p;
    }
}//预处理 
ll sumy(ll x){x%=p;return x*(x+1)%p*inv2%p;} //一次方求和 
ll sumq(ll x){
	x%=p; 
	return x*(x+1)%p*(2*x+1)%p*inv6%p;
} //二次方求和 
unordered_map<ll,ll> sumsq;
ll ds(ll x){
	if(x<N){
		return sum[x];
	}
	if(sumsq.count(x)){
		return sumsq[x];
	}
	else{
		ll ans=0;
		ll tmp=sumy(x);
		ans=tmp*tmp%p;
		for(ll i=2,j;i<=x;i=j+1){
			j=x/(x/i);
			ll stmp=(sumq(j)-sumq(i-1)+p)%p;
			ans=(ans-stmp*ds(x/i)%p+p)%p;
		}
		sumsq[x]=(ans+p)%p;
		return (ans+p)%p;
	}
} //杜教筛 
int main(){
	cin>>p>>n;
	inv2=fp(2,p-2);
	inv6=fp(6,p-2); //求逆元 
	init();
	ll ans=0;
	for(ll i=1,j;i<=n;i=j+1){
		j=n/(n/i);
		ll tmp=sumy(n/i);
		tmp=tmp*tmp%p;
		ll cnt=(ds(j)-ds(i-1)+p)%p;
		ans+=tmp*cnt%p;
		ans%=p;
	} //数论分块 
	cout<<(ans+p)%p;
	return 0; 
}
