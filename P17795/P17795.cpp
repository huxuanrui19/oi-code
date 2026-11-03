#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
const ll inf=1e18,mod=1e9+7;
ll n,k,a[N],b[N];
bool check(ll x){
    ll cnt=0,res=k,lst=0;
    for(int i=n;i>=1;i--){
        if(cnt<a[i]&&res>0) res--,cnt=x;
        if(cnt>=a[i]) cnt-=a[i];
        else{
            lst=i;
            break;
        }
    }
    if(lst==0) return 1;
    ll cur=x;
    for(int i=1;i<=lst;i++){
        if(a[i]>cur) return 0;
        cur-=a[i];
        cur=min(cur+b[i],x);
    }
    return 1;
}
int main(){
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i]>>b[i];
    ll l=1,r=1e18,ans=0;
    while(l<=r){
        ll mid=(l+r)>>1;
        if(check(mid)){
            ans=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    cout<<ans;
    return 0;
}