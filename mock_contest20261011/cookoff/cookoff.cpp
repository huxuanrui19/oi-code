#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10,M=2e3+10;
const ll inf=1e18,mod=1e9+7;
ll n,m,a[N],b[N],s[N],t[N],p[N],q[N];
ll suma[N],sumb[N],sump[N],sumq[N];
ll dp[M][M];
int main(){
    freopen("cookoff.in","r",stdin);
    freopen("cookoff.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i]>>s[i]>>p[i];
    for(int i=1;i<=m;i++) cin>>b[i]>>t[i]>>q[i];
    int num=s[1];
    for(int i=2;i<=n;i++){
        if(num!=s[i]) num=-1;
    }
    for(int i=1;i<=m;i++){
        if(num!=t[i]) num=-1;
    }
    for(int i=1;i<=n;i++){
        suma[i]=suma[i-1]+a[i];
        sump[i]=sump[i-1]+p[i];
    }
    for(int i=1;i<=m;i++){
        sumb[i]=sumb[i-1]+b[i];
        sumq[i]=sumq[i-1]+q[i];
    }
    if(num!=-1){
        ll cnt=0,ans=-inf;
        for(int i=0;i<=n;i++){
            if(suma[i]>num) continue;
            cnt=0;
            cnt+=sump[i];
            int pos=lower_bound(sumb+1,sumb+m+1,num-suma[i])-sumb-1;
            cnt+=sumq[pos];
            ans=max(ans,cnt);
        }
        cout<<ans;
    }
    else{
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                dp[i][j]=-inf;
                if(i==0&&j==0) dp[i][j]=0;
                if(i>0) dp[i][j]=dp[i-1][j]+p[i]*((suma[i]+sumb[j])<=s[i]);
                if(j>0) dp[i][j]=max(dp[i][j],dp[i][j-1]+q[j]*((suma[i]+sumb[j])<=t[j]));
            }
        }
        cout<<dp[n][m];
    }
    return 0;
}