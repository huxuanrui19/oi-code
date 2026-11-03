#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
const ll inf=1e18,mod=1e9+7;
ll n,k,a[N],h[N],x[N],vis[N];
int main(){
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i]>>h[i];
    for(int i=1;i<=k;i++) cin>>x[i];
    sort(x+1,x+k+1);
    ll ans=0;vector<pair<int,int> > v;
    for(int i=1;i<=n;i++){
        int pos=lower_bound(x+1,x+k+1,a[i])-x;
        ll minn=1e18;
        if(pos>1) minn=min(minn,a[i]-x[pos-1]);
        if(pos<=k) minn=min(minn,x[pos]-a[i]);
        if(minn<=h[i]){
            ans+=minn;
            if((a[i]-x[pos-1])<(x[pos]-a[i])||pos>k) vis[pos-1]=1;
            else if((a[i]-x[pos-1])>(x[pos]-a[i])||pos<=1) vis[pos-1]=1;
            else v.push_back({i,pos});
        }
        else ans+=h[i];
    }
    vector<int> res;
    for(auto d:v){
        int u=d.first,pos=d.second;
        if(vis[pos]||vis[pos-1]) continue;
        else res.push_back({pos});
    }
    //
    return 0;
}