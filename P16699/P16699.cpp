#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
const ll inf=1e18,mod=1e9+7;
ll n,m,k,b[N],c[N],vis[N];
struct node{
    ll num,idx;
    bool operator <(const node &x) const{
        return num>x.num;
    }
}a[N];
int main(){
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++) cin>>b[i];
    for(int i=1;i<=m;i++){
        int l,r;cin>>l>>r;
        l++;r++;
        c[l]++;c[r+1]--;
    }
    for(int i=1;i<=n;i++) c[i]+=c[i-1];
    for(int i=1;i<=n;i++){
        a[i]={c[i],b[i]};
        if(b[i]!=-1) vis[b[i]]=1;
    }
    sort(a+1,a+n+1);
    int j=n-1;
    ll ans=0;
    for(int i=1;i<=n;i++){
        if(a[i].idx!=-1) ans+=a[i].num*a[i].idx;
        else{
            while(vis[j]) j--;
            ans+=j*a[i].num;
            j--;
        }
    }
    cout<<ans;
    return 0;
}