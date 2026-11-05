#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
const ll inf=1e18,mod=1e9+7;
ll n,k,x[N],vis[N];
struct node{
    ll a,h;
    bool operator <(const node &x) const{
        return a<x.a;
    }
}arr[N];
int main(){
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>arr[i].a>>arr[i].h;
    sort(arr+1,arr+n+1);
    for(int i=1;i<=k;i++) cin>>x[i];
    sort(x+1,x+k+1);
    ll ans=0;
    for(int i=1;i<=n;i++){
        int pos=lower_bound(x+1,x+k+1,arr[i].a)-x;
        ll minn1=1e18,minn2=1e18;
        if(pos>1) minn1=min(minn1,arr[i].a-x[pos-1]+1-vis[pos-1]);
        if(pos<=k) minn2=min(minn2,x[pos]-arr[i].a+1-vis[pos]);
        if(min(minn1,minn2)<=arr[i].h){
            ans+=min(minn1,minn2);
            if(minn1<minn2) vis[pos-1]=1;
            else if(minn1>minn2) vis[pos]=1;
            else vis[pos]=1;
        }
        else ans+=arr[i].h;
    }
    cout<<ans;
    return 0;
}