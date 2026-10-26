#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=500+10;
const ll M=245,K=1e6+10,mod=998244353;
ll n,k;
ll a[N][N];int pos[K],dp[2][N][M],gd[K];
vector<int> v;
int main(){
    //freopen("ground\\4.in","r",stdin);
    //freopen("ground.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=k;i++){
        if(k%i==0) v.push_back(i);
    }
    for(int i=0;i<(int)v.size();i++) pos[v[i]]=i;
    for(ll i=0;i<=k;i++) gd[i]=__gcd(k,i);

    if(a[1][1]==-1) dp[1][1][1]=0;
    else dp[1][1][pos[__gcd(a[1][1],k)]]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==1&&j==1) continue;
            if(a[i][j]==-1) continue;
            if(i>1){
                for(ll t=0;t<(int)v.size();t++){
                    ll num=v[t];
                    num=gd[num*a[i][j]%k];
                    dp[1][j][pos[num]]=(dp[1][j][pos[num]]+dp[0][j][t])%mod;
                }
            }
            if(j>1){
                for(ll t=0;t<(int)v.size();t++){
                    ll num=v[t];
                    num=gd[num*a[i][j]%k];
                    dp[1][j][pos[num]]=(dp[1][j][pos[num]]+dp[1][j-1][t])%mod;
                }
            }
        }
        for(int j=1;j<=n;j++){
            for(int t=0;t<(int)v.size();t++){
                dp[0][j][t]=dp[1][j][t];
                dp[1][j][t]=0;
            }
        }
    }
    cout<<dp[0][n][pos[k]];
    return 0;
}