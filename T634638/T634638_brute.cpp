#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
const ll mod=1e9+7;
ll n,d,tmp[N],pw[N],dp[N][2];
unordered_map<ll,ll> mp1;
unordered_map<ll,ll> mp2;
string s;
int main(){
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>s>>d;
    n=s.size();
    s=' '+s;
    tmp[n]=(s[n]-'0')%d;
    ll sum=0;
    if(tmp[n]==0) sum=dp[n][1]=1;
    else dp[n][0]=1;
    mp1[tmp[n]]+=dp[n][1]+dp[n][0];mp2[tmp[n]]+=dp[n][1];
    pw[0]=1;for(int i=1;i<=n;i++) pw[i]=pw[i-1]*10%d;
    for(int i=n-1;i>=1;i--){
        tmp[i]=(tmp[i+1]+(s[i]-'0')*pw[n-i]%d)%d;
        dp[i][1]=(mp1[tmp[i]]+(tmp[i]%d==0))%mod;
        dp[i][0]=(sum-mp2[tmp[i]]+(tmp[i]%d!=0))%mod;
        dp[i][0]=(dp[i][0]+mod)%mod;
        sum=(sum+dp[i][1])%mod;
        mp1[tmp[i]]=(mp1[tmp[i]]+dp[i][1]+dp[i][0])%mod;
        mp2[tmp[i]]=(mp2[tmp[i]]+dp[i][1])%mod;
        cerr<<dp[i][1]<<" "<<dp[i][0]<<"\n";
    }
    //cerr<<pw[1]<<" "<<pw[2]<<"\n";
    //cerr<<s<<" "<<d<<"\n";
    cout<<(dp[1][0]+dp[1][1])%mod;
    return 0;
}