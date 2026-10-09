#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3e5+10;
const ll mod=1e9+7;
ll n,l,a[N],b[N],dp[N][2],tree[N<<1];
inline ll lowbit(ll x){return x&(-x);}
void update(ll x,ll d){
    while(x<(N<<1)){
        tree[x]=(tree[x]+d)%mod;
        x+=lowbit(x);
    }
}
ll query(ll x){
    ll sum=0;
    while(x){
        sum+=tree[x];sum%=mod;
        x-=lowbit(x);
    }
    return sum;
}
int main(){
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n>>l;
    for(int i=1;i<=n;i++) cin>>a[i]>>b[i];
    dp[1][1]=1;
    update(b[1],dp[1][1]);
    for(int i=2;i<=n;i++){
        dp[i][1]=(query(a[i]+l)-query(a[i]-1)+1+mod)%mod;
        dp[i][0]=(dp[i-1][1]+dp[i-1][0])%mod;
        update(b[i],dp[i][1]);
    }
    cout<<(dp[n][1]+dp[n][0])%mod;
    return 0;
}