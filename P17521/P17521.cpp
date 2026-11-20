#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
const ll inf=1e18,mod=1e9+7;
ll n,a[N];
int main(){
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t;cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        ll ans=-1e18,x=0,y=0;
        for(int i=1;i<=n;i++){
            if(a[i]>0) x++;
            else if(a[i]==0) y++;
        }
        if(n==1) cout<<a[1]<<"\n";
        else if(x%2==0&&y==0){
            ll sum=0;
            for(int i=1;i<=n;i++) sum+=abs(a[i]);
            for(int i=1;i<=n;i++) ans=max(ans,sum-abs(a[i])*2);
            cout<<ans<<"\n";
        }
        else{
            ll sum=0;
            for(int i=1;i<=n;i++) sum+=abs(a[i]);
            cout<<sum<<"\n";
        }
    }
    return 0;
}