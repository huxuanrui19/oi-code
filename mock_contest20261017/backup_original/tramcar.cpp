#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3e5+10;
const ll inf=1e12,mod=1e9+7;
int n;
ll k,a[N];
struct node{
    ll num,idx;
    bool operator <(const node &x) const{
        if(num!=x.num) return num<x.num;
        else return idx<x.idx;
    }
}arr[N];
int main(){
    freopen("tramcar.in","r",stdin);
    freopen("tramcar.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(k==0){
        for(int i=1;i<=n;i++) arr[i]={a[i],i};
        sort(arr+1,arr+n+1);
        ll ans=0;
        for(int i=1;i<=n;i++){
            ans=max(ans,abs(arr[i].idx-i));
        }
        cout<<ans;
    }
    else if(k==inf){
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(a[i]==0) continue;
            else arr[++cnt]={a[i],i};
        }
        sort(arr+1,arr+cnt+1);

    }
    return 0;
}