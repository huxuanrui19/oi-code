#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=7e3+10;
const ll maxn=1e18,mod=998244353;
ll n,x,y,k,dp[2][N];
int main(){
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n>>x>>y>>k;
    memset(dp,0,sizeof(dp));
    ll dis=min(abs(x-y),n-abs(x-y));
    dp[0][dis]=1;
    for(int i=0;i<k;i++){
        int now=i%2,nxt=(i+1)%2;
        for(int j=1;j<=n/2;j++){
            dp[nxt][j]=(dp[nxt][j]+dp[now][j])%mod;
            dp[nxt][j-1]=(dp[nxt][j-1]+dp[now][j])%mod;
            if(j>=2) dp[nxt][abs(j-2)]=(dp[nxt][abs(j-2)]+dp[now][j])%mod;
        }
        for(int j=0;j<=n/2;j++) dp[now][j]=0;
    }
    ll ans=0;
    for(int j=1;j<=n/2;j++) ans=(ans+dp[k%2][j])%mod;
    cout<<ans;
    return 0;
}