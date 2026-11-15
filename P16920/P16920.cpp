#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=8e3+10;
const ll inf=1e18,mod=1e9+7;
ll n,a[N],sum[N];
int main(){
    freopen("reverse.in","r",stdin);
    freopen("reverse.out","w",stdout);
    //freopen("err.out","w",stderr);
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t;cin>>t;
    while(t--){
        cin>>n;for(int i=1;i<=n;i++) cin>>a[i];
        ll ans=0,all=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                all+=(a[i]>a[j]);
            }
        }
        //cerr<<all<<"\n";
        for(int i=1;i<=n;i++){
            for(int j=1;j<i;j++) sum[i]+=(a[i]<a[j]);
        }
        ans=all;
        for(int i=1;i<=n;i++){
            ll num=0;
            for(int j=i;j<=n;j++){
                num+=sum[j];
                //cerr<<i<<" "<<j<<" "<<num<<"\n";
                ll l=j-i+1;
                ans=max(ans,all-2*num+(l*(l-1)/2));
            }
            for(int j=i;j<=n;j++){
                if(a[j]<a[i]) sum[j]--;
            }
        }
        cout<<ans<<"\n";
        for(int i=1;i<=n;i++) sum[i]=0;
    }
    return 0;
}