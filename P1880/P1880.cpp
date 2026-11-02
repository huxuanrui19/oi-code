#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100+10;
const ll inf=1e18,mod=1e9+7;
ll n,a[N<<1],sum[N<<1],dp[N<<1][N<<1],f[N<<1][N<<1];
int main(){
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) a[i+n]=a[i];
    for(int i=1;i<=n*2;i++) sum[i]=sum[i-1]+a[i];
    memset(dp,0x3f,sizeof(dp));
    for(int i=1;i<=n*2;i++) dp[i][i]=0;
    for(int l=2;l<=n;l++){
        for(int i=1;i+l-1<=2*n;i++){
            int j=i+l-1;
            for(int k=i;k<j;k++){
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+sum[j]-sum[i-1]);
                f[i][j]=max(f[i][j],f[i][k]+f[k+1][j]+sum[j]-sum[i-1]);
            }
        }
    }
    ll ans=1e18,cnt=0;
    for(int i=1;i<=n;i++){
        ans=min(ans,dp[i][i+n-1]);
        cnt=max(cnt,f[i][i+n-1]);
    }
    cout<<ans<<"\n"<<cnt;
    return 0;
}