#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
const ll inf=1e18,mod=1e9+7;
int n,m,c[N],col[N];
ll pw[N],fac[N],inv[N];
vector<int> g[N];
inline ll qp(ll n,ll k){
    ll sum=1;
    for(;k;k>>=1,n=n*n%mod){
        if(k&1) sum=sum*n%mod;
    }
    return sum;
}
inline ll C(ll n,ll m){
    return (fac[n]*inv[n-m])%mod*inv[m]%mod;
}
ll solve(int s){
    col[s]=1;
    queue<int> q;q.push(s);
    bool flag=0;ll sum=(col[s]==c[s]),k=0;
    while(!q.empty()){
        int u=q.front();q.pop();k++;
        for(auto d:g[u]){
            if(col[d]!=-1){
                if(col[d]==col[u]) flag=1;
            }
            else{
                col[d]=col[u]^1;
                sum+=(col[d]==c[d]);
                q.push(d);
            }
        }
    }
    if(flag) return pw[k-1];
    else return C(k,sum);
}
int main(){
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n>>m;
    pw[0]=fac[0]=1;
    for(int i=1;i<=n;i++) pw[i]=(pw[i-1]*2)%mod;
    for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
    inv[n]=qp(fac[n],mod-2);
    for(int i=n-1;i>=0;i--) inv[i]=inv[i+1]*(i+1)%mod;
    for(int i=1;i<=n;i++) cin>>c[i];
    for(int i=1,a,b;i<=m;i++){
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    ll ans=1;
    memset(col,-1,sizeof(col));
    for(int i=1;i<=n;i++){
        if(col[i]==-1){
            ans=(ans*solve(i))%mod;
        }
    }
    cout<<ans;
    return 0;
}