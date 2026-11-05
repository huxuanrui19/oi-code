#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
ll n,m,a[N],sum[N];
ll getans(int l,int r){
    int ans=0,pos=r;
    while(l<=r){
        int mid=(l+r)>>1;
        if((a[pos]*(pos-mid+1)-(sum[pos]-sum[mid-1]))<=m){
            r=mid-1;ans=mid;
        }
        else l=mid+1;
    }
    return ans;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    ll ans=1;
    for(int i=1;i<=n;i++){
        ans=max(ans,i-getans(1,i)+1);
    }
    cout<<ans;
    return 0;
}
