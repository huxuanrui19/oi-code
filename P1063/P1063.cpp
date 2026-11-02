#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100+10;
const ll inf=1e18,mod=1e9+7;
ll n,a[N<<2],dp[N<<1][N<<1];
int main(){
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n;for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) a[i+n]=a[i];
    for(int i=1;i<=n;i++) a[i+2*n]=a[i];
    for(int i=1;i<=n*2;i++) dp[i][i]=0;
    for(int l=2;l<=n;l++){
        for(int i=1;i+l-1<=2*n;i++){
            int j=i+l-1;
            for(int k=i;k<j;k++){
                dp[i][j]=max(dp[i][j],dp[i][k]+dp[k+1][j]+a[i]*a[j+1]*a[k+1]);
            }
        }
    }
    ll ans=0;
    for(int i=1;i<=n;i++) ans=max(ans,dp[i][i+n-1]);
    cout<<ans;
    return 0;
}