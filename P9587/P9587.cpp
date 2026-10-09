#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
const ll maxn=1e18,mod=1e9+7;
ll c,n,k,sum[N];
struct node{
    ll a,ans,idx;
    bool operator <(const node &x){
        return a>x.a;
    }
}a[N];
bool cmp(node x,node y){
    return x.idx<y.idx;
}
int main(){
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>c>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i].a;
    for(int i=1;i<=n;i++) a[i].idx=i;
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i].a;
    for(int i=1;i<=n;i++){
        if(a[i].a==a[k].a) a[i].ans=0;
        else if(a[i].a<a[k].a) a[i].ans=a[k].a-a[i].a;
        else a[i].ans=a[i].a*(k-i)-sum[k]+sum[i];
    }
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++) cout<<a[i].ans<<"\n";
    return 0;
}