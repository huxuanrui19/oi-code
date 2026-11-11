#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=500+10;
const ll inf=1e18,mod=1e9+7;
ll n,k,x,c,a[N],dp[N];
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n>>k>>x>>c;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(k==1){
        ll ans=0;
        for(int i=1;i<=n;i++){
            if(a[i]<x) ans+=a[i];
            else ans+=x;
        }
        cout<<ans;
    }
    else if(k==n){
        ll ans=x,sum=0;
        for(int i=1;i<=n;i++) sum+=a[i];
        ans=min(ans,sum);
        cout<<ans;
    }
    else{
        bool flag=1;
        for(int i=1;i<=n;i++){
            if(a[i]>c) flag=0;
        }
        if(flag){
            for(int i=1;i<=n;i++){
                dp[i]=dp[i-1]+a[i];
                if(i>=k) dp[i]=min(dp[i],dp[i-k]+x);
            }
            cout<<dp[n];
        }
        else{
            ll ans=0;
            for(int i=1;i<=n;i++) ans+=a[i];
            cout<<ans;
        }
    }
    return 0;
}