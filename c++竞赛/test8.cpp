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

const int N=1e7+10;
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
            phi[i*pri[j]]=(phi[i]*(pri[j]-1))%p;  // 修正phi的计算
        }
    }
    sum[1]=1*1%p*phi[1]%p;  // 添加更多取模
    for(ll i=2;i<N;i++){
        sum[i]=(sum[i-1]+((i*i)%p*phi[i]%p))%p;
    }
}//预处理

ll sumy(ll x){x%=p;return x*(x+1)%p*inv2%p;} //一次方求和
ll sumq(ll x){  // 改为返回ll
    x%=p; 
    return x*(x+1)%p*(2*x+1)%p*inv6%p;  // 添加更多取模
} //二次方求和

unordered_map<ll,ll> sumsq;  // 改用unordered_map可能更快
ll ds(ll x){  // 改为返回ll
    if(x<N){
        return sum[x];
    }
    if(sumsq.count(x)){  // 更安全的查找方式
        return sumsq[x];
    }
    else{
        ll ans=0;
        ll tmp=sumy(x);
        ans=tmp*tmp%p;
        for(ll i=2,j;i<=x;i=j+1){
            j=x/(x/i);
            ll stmp=(sumq(j)-sumq(i-1)+p)%p;  // 防止负数
            ans=(ans-stmp*ds(x/i)%p+p)%p;  // 及时取模
        }
        sumsq[x]=ans;
        return ans;
    }
} //杜教筛

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>p>>n;
    inv2=fp(2,p-2);
    inv6=fp(6,p-2); //求逆元
    init();
    ll ans=0;
    for(ll i=1,j;i<=n;i=j+1){
        j=n/(n/i);
        ll tmp=sumy(n/i);
        tmp=tmp*tmp%p;
        ll cnt=(ds(j)-ds(i-1)+p)%p;  // 防止负数
        ans=(ans+tmp*cnt%p)%p;
    } //数论分块
    cout<<(ans+p)%p;
    return 0;
}
