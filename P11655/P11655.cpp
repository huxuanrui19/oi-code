#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+10;
const ll maxn=1e18,mod=1e9+7;
ll fac[N],inv[N];
ll qp(ll n,ll k){
    ll sum=1;
    while(k){
        if(k&1) sum=sum*n%mod;
        n=n*n%mod;
        k>>=1;
    }
    return sum;
}
void init(){
    fac[0]=1;
    for(int i=1;i<N;i++) fac[i]=fac[i-1]*i%mod;
    inv[N-1]=qp(fac[N-1],mod-2);
    for(int i=N-2;i>=0;i--) inv[i]=inv[i+1]*(i+1)%mod;
}
ll C(ll n,ll m){
    if(m>n||m<0||n<0) return 0;
    return fac[n]*inv[m]%mod*inv[n-m]%mod;
}
ll cal(ll n,ll m){
    return (C(n+m,n)+C(n+m-2,m-1)*(n+m-1)*2)%mod;
}
int main(){
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll t;cin>>t;init();
    while(t--){
        ll n,m;cin>>n>>m;
        cout<<cal(n,m)<<"\n";
    }
    return 0;
}