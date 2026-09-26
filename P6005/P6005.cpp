#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e3+10;
vector<int> g[N];
ll n,m,a[N],dp[N][N];
ll c;
int main(){
    //freopen(".in","r",stdin);
    //freopen(".out","r",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m>>c;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        g[v].push_back(u);
    }
    memset(dp,-1,sizeof(dp));
    dp[0][1]=0;
    for(int i=1;i<N;i++){
        for(int j=1;j<=n;j++){
            for(auto d:g[j]){
                if(dp[i-1][d]==-1) continue;
                dp[i][j]=max(dp[i][j],dp[i-1][d]+a[j]);
            }
        }
    }
    ll ans=0;
    for(ll i=0;i<N;i++){
        ans=max(ans,dp[i][1]-c*i*i);
    }
    cout<<ans;
    return 0;
}