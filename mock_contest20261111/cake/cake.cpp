#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
const ll inf=1e18,mod=1e9+7;
int n,a[N];
int main(){
    freopen("cake.in","r",stdin);
    freopen("cake.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n;for(int i=1;i<=n;i++) cin>>a[i];
    if(n<=2) cout<<"0";
    else{
        if(a[n-1]!=a[n]) cout<<(a[n-1]-a[1]);
        else{
            int cnt=unique(a+1,a+n+1)-a-1;
            ll ans=max(a[cnt-1]-a[1],a[cnt]-a[2]);
            cout<<ans<<"\n";
        }
    }
    return 0;
}