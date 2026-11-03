#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e3+10;
const ll inf=1e18,mod=201701;
ll n,r,a[N];
int main(){
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n>>r;
    for(int i=1;i<=n;i++){
        a[i]=r%100+1;
        r=(r*6807+2831)%mod;
    }
    sort(a+1,a+n+1);
    ll ans=0,sum=0;
    for(int i=1;i<=n;i++) sum+=a[i],ans+=sum;
    cout<<ans;
    return 0;
}