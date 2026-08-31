#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e3+10;
const ll mod=998244353;
ll n,m,a[N];
inline ll qp(ll n,ll k){
    ll sum=1;
    while(k){
        if(k&1) sum=sum*n%mod;
        n=n*n%mod;
        k>>=1;
    }
    return sum;
}
#define M ((N)<<1)
ll fac[M],inv[M],pow2[M];
void init(){
    pow2[0]=1;
    for(int i=1;i<M;i++) pow2[i]=pow2[i-1]*2%mod;
    fac[0]=1;
    for(int i=1;i<M;i++) fac[i]=fac[i-1]*i%mod;
    inv[M-1]=qp(fac[M-1],mod-2);
    for(int i=M-2;i>=0;i--) inv[i]=inv[i+1]*(i+1)%mod;
}
inline ll C(ll n,ll m){
    if(n<m||m<0||n<0) return 0;
    return fac[n]*inv[m]%mod*inv[n-m]%mod;
}
int main(){
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int c,t;cin>>c>>t;
    init();
    while(t--){
        cin>>n>>m;
        for(int i=1;i<=n;i++) cin>>a[i];
        sort(a+1,a+n+1);
        ll ans=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1,k=0;j<=n;j++){
                if(a[i]==a[j]) continue;
                if(2*a[i]<=a[j]) break;
                while(a[i]+a[k+1]<a[j]&&k<n) k++;
                ans=(ans+pow2[k]*C(n-i-1,m-2-(n-j))%mod)%mod;
            }
        }
        ans=qp(2,n)-ans;ans=(ans%mod+mod)%mod;
        cout<<ans<<"\n";
    }
    return 0;
}