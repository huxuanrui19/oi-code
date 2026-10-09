#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e7+10;
const ll maxn=1e18,mod=998244353;
int a[N],fac[N],inv[N];
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
    for(int i=1;i<N;i++) fac[i]=ll(fac[i-1])*ll(i)%mod;
    inv[N-1]=qp(fac[N-1],mod-2);
    for(int i=N-2;i>=0;i--) inv[i]=ll(inv[i+1])*ll(i+1)%mod;
}
inline ll C(ll n,ll m){
    if(n<0||m<0||n<m) return 0;
    return ll(fac[n])*ll(inv[m])%mod*ll(inv[n-m])%mod;
}
int main(){
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t;cin>>t;
    init();
    while(t--){
        ll n,m;cin>>n>>m;
        for(int i=1;i<=n;i++) cin>>a[i];
        ll lst=-1,sum=0,len=0,num=0;
        for(int i=1;i<=n;i++){
            if(a[i]>lst) len++,lst=a[i];
            else sum+=(len-1),lst=a[i],len=1,num++;
        }
        if(len) sum+=(len-1),num++;
        if(m<num) cout<<"0\n";
        else{
            ll ans=0;
            for(int i=0;i<=m-num;i++) ans=(ans+C(sum,i))%mod;
            cout<<ans<<"\n";
        }
    }
    return 0;
}