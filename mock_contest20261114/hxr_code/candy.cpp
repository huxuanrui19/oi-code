#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10,M=5e3+10;
const ll inf=1e18,mod=1e9+7;
ll n,a[N],dp[M][M];
int main(){
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n;for(int i=1;i<=n;i++) cin>>a[i];
    int flag=1;
    for(int i=1;i<=n;i++){
        if(a[i]!=a[1]) flag=0;
    }
    if(flag==1){
        for(int i=1;i<=ceil(n/2.0);i++) cout<<a[1]*i<<"\n";
    }
    else if(n<M){
        for(int i=1;i<=n;i++) dp[0][i]=-inf;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dp[i][j]=max(dp[i][j],dp[i-1][j]);
                ll cnt=0;
                if(i>1) cnt+=dp[i-2][j-1];
                dp[i][j]=max(dp[i][j],a[i]+cnt);
            }
        }
        for(int i=1;i<=ceil(n/2.0);i++) cout<<dp[n][i]<<"\n";
    }
    else{
        ll ans=0;
        for(int i=1;i<=ceil(n/2.0);i++){
            ans+=a[n-2*(i-1)];
            cout<<ans<<"\n";
        }
    }
    return 0;
}