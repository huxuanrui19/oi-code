#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e3+10;
const ll maxn=1e18,mod=1e9+7;
int k,n,dp[N][N][2],sum[N][N][2];
int main(){
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n>>k;
    if(n==k){
        cout<<1;
        return 0;
    }
    dp[k][k][1]=dp[k][k][0]=1;
    for(int j=1;j<=n;j++) sum[k][j][0]=sum[k][j-1][0]+dp[k][j][0];
    for(int j=1;j<=n;j++) sum[k][j][1]=sum[k][j-1][1]+dp[k][j][1];
    for(int i=k+1;i<=n;i++){
        for(int j=1;j<i;j++){
            dp[i][j][0]=sum[i-j][j-1][1];
            dp[i][j][1]=(sum[i-j][i-1][0]-sum[i-j][j][0]+mod)%mod;
        }
        for(int j=1;j<=n;j++) sum[i][j][0]=(sum[i][j-1][0]+dp[i][j][0])%mod;
        for(int j=1;j<=n;j++) sum[i][j][1]=(sum[i][j-1][1]+dp[i][j][1])%mod;
    }
    ll ans=0;
    for(int i=1;i<=n;i++) ans=((ans+dp[n][i][0])%mod+dp[n][i][1])%mod;
    cout<<ans;
    return 0;
}