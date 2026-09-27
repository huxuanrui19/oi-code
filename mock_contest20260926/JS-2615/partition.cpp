#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10;
const ll mod=998244353;
ll n,k,a[N],sum[N];
int main(){
    freopen("partition.in","r",stdin);
    freopen("partition.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=n;i>=1;i--) sum[i]=(sum[i+1]+a[i])%mod;
    ll lst=n,ans=0,cnt=0;
    for(int i=1;i<=n;i++) cnt=(a[i]*a[i]+cnt)%mod;
    for(int i=1;i<=n;i++) ans=(ans+(a[i]+1)*(a[i]+1)%mod)%mod;
    for(ll i=2;i<=k;i++){
        while(abs(a[lst]+i)>=abs(a[lst])&&lst>0) lst--;
        ll cur=2*(sum[1]-sum[lst+1]+mod)%mod+lst;cur%=mod;
        cur=(cur+2*i*(sum[lst+1])%mod+i*i%mod*(n-lst)%mod)%mod;
        cur=(cur+cnt)%mod;ans=(ans+cur)%mod;
    }
    cout<<ans;
    return 0;
}