#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2.5e5+10;
const ll inf=1e18,mod=998244353;
int n,fa[N];
vector<int>g[N];
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
    fac[0]=1;for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
    inv[n]=qp(fac[n],mod-2);for(int i=n-1;i>=0;i--) inv[i]=inv[i+1]*(i+1)%mod;
}
inline ll C(ll n,ll k){
    return fac[n]*inv[k]%mod*inv[n-k]%mod;
}
void dfs(int u,int f){
    fa[u]=f;
    for(auto d:g[u]){
        if(d==f)continue;
        dfs(d,u);
    }
    return;
}
int main(){
    freopen("treecoloring.in","r",stdin);
    freopen("treecoloring.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    init();
    for(int i=1;i<n;i++){
        int x,y;cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    if(g[1].size()==n-1) cout<<fac[n-1]<<"\n";
    else if(n<=10){
        int num[n+1];
        for(int i=1;i<=n;i++) num[i]=i;
        dfs(1,1);
        ll ans=0;
        do{
            for(int i=2;i<=n;i++){
                if(num[fa[i]]-1==num[i]) goto out;
            }
            ans++;
            out:;
        }while(next_permutation(num+1,num+n+1));
        cout<<ans;
    }
    else{
        ll ans=0;
        for(int i=0;i<n;i++){
            if(i%2==0) ans=(ans+fac[n-i]*C(n-1,i)%mod)%mod;
            else ans=((ans-fac[n-i]*C(n-1,i)%mod)%mod+mod)%mod;
        }
        cout<<ans;
    }
    return 0;
}
