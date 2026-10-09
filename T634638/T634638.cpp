#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
const ll mod=1e9+7;
string s;
ll d,n,a,b,y,invb,sum,pre[N],c[N],dp[N][2],pw[N],inv[N];
inline ll qp(ll n,ll k,ll b){
    ll sum=1;
    while(k){
        if(k&1) sum=sum*n%b;
        n=n*n%b;
        k>>=1;
    }
    return sum;
}
unordered_map<ll,ll> mp1;
unordered_map<ll,ll> mp2;
ll exgcd(ll a,ll b,ll &x,ll &y){
    if(b==0){
        x=1;y=0;
        return a;
    }
    ll d=exgcd(b,a%b,y,x);
    y=y-(a/b)*x;
    return d;
}
int main(){
    //freopen("D:\\OI\\T634638\\ex_division3.in","r",stdin);
    //freopen(".out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>s>>d;n=s.size();
    s=' '+s;a=d;b=d;
    while(b%2==0) b/=2;
    while(b%5==0) b/=5;
    a/=b;
    for(int i=1;i<=n;i++) pre[i]=(pre[i-1]*10+s[i]-'0')%d;
    exgcd(10,b,invb,y);invb=(invb+b)%b;
    inv[0]=pw[0]=1;
    for(int i=1;i<=n;i++){
        inv[i]=inv[i-1]*invb%b;
        pw[i]=pw[i-1]*10%d;
    }
    for(int i=1;i<=n;i++) c[i]=pre[i]*inv[i]%b;
    dp[0][0]=1;sum=1;
    for(int i=1;i<=n;i++){
        if(pre[i]%a==0) dp[i][0]=mp1[c[i]];
        ll num=0;
        for(int j=0;j<19;j++){
            if(i-j-1<0) break;
            num=(num+pw[j]*(s[i-j]-'0'))%d;
            if(num==0) dp[i][0]=(dp[i][0]+dp[i-j-1][0]+dp[i-j-1][1])%mod;
        }
        dp[i][1]=sum;   
        if(pre[i]%a==0) dp[i][1]-=mp2[c[i]],(dp[i][1]+=mod)%=mod;
        num=0;
        for(int j=0;j<19;j++){
            if(i-j-1<0) break;
            num=(num+pw[j]*(s[i-j]-'0'))%d;
            if(num==0) dp[i][1]=(dp[i][1]-dp[i-j-1][0]+mod)%mod;
        }
        if(i-19>=0){
            mp1[c[i-19]]+=dp[i-19][0]+dp[i-19][1];
            mp1[c[i-19]]%=mod;
            mp2[c[i-19]]+=dp[i-19][0];
            mp2[c[i-19]]%=mod;
        }
        sum+=dp[i][0];sum%=mod;
    }
    cout<<(dp[n][0]+dp[n][1]+mod)%mod;
    return 0;
}