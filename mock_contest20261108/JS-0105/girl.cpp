#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=450+10;
ll n,d[N<<1],son[N<<1],dp[N<<1][N][2];
int main(){
    freopen("girl.in","r",stdin);
    freopen("girl.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>d[i];
    for(int i=1;i<=n;i++) son[i]=1;
    for(int i=n;i>=1;i--) son[i]+=son[i<<1]+son[i<<1|1];
    memset(dp,-0x3f,sizeof(dp));
    for(int i=n+1;i<=2*n+1;i++) dp[i][0][0]=dp[i][0][1]=0;
    for(int i=n;i>=1;i--){
        int ls=(i<<1),rs=(i<<1|1);
        if(ls>n&&rs>n){
            dp[i][1][0]=0;
            dp[i][0][1]=0;
        }
        for(int t=0;t<=son[i];t++){
            for(int lt=0;lt<=min(son[ls],1ll*t);lt++){
                int rt=t-lt;
                for(int mask=0;mask<=3;mask++){
                    int lp=mask>>1,rp=mask&1;
                    if(rt&&rt-1<=son[rs]) dp[i][t][0]=max(dp[i][t][0],dp[ls][lt][lp]+dp[rs][rt-1][rp]+d[ls]*(lp==0)+d[rs]*(rp==0));
                    if(rt<=son[rs]) dp[i][t][1]=max(dp[i][t][1],dp[ls][lt][lp]+dp[rs][rt][rp]+d[ls]*(lp==1)+d[rs]*(rp==1));
                }
            }
        }
    }
    cout<<max(dp[1][n/2][0],dp[1][n/2][1]);
    return 0;
}
