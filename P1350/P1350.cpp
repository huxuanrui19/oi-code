#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e3+10;
const ll inf=1e18,mod=1e5+3;
ll a,b,c,d,k,fac[N],inv[N];
ll qp(ll n,ll k){
    ll sum=1;
    while(k){
        if(k&1) sum=sum*n%mod;
        n=n*n%mod;k>>=1;
    }
    return sum;
}
inline ll A(ll n,ll m){
    if(n<0||m<0||n<m) return 0;
    return fac[n]*inv[n-m]%mod;
}
int main(){
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>a>>b>>c>>d>>k;
    fac[0]=1;for(int i=1;i<N;i++) fac[i]=fac[i-1]*i%mod;
    inv[N-1]=qp(fac[N-1],mod-2);for(int i=N-2;i>=0;i--) inv[i]=inv[i+1]*(i+1)%mod;
    ll ans=0;
    for(ll i=0;i<=k;i++){
        for(ll j=0;j<=k-i;j++){
            ans+=A(b,i)*A(a,i)%mod*inv[i]%mod*A(c,j)%mod*A(d,j)%mod*inv[j]%mod*A(a-i,k-i-j)%mod*A(d-j,k-i-j)%mod*inv[k-i-j]%mod;
            ans%=mod;
        }
    }
    cout<<ans;
    return 0;
}