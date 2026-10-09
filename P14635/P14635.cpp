#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
const ll maxn=1e18,mod=1e9+7;
ll n,m;
struct node{
    ll x,y;
    bool operator <(const node &t){
        return x<t.x;
    }
}a[N];
int main(){
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i].x>>a[i].y;
    sort(a+1,a+n+1);
    ll pos=0,minn=1e18;
    for(int i=1;i<=n;i++){
        if(minn>a[i].x+a[i].y){
            minn=a[i].x+a[i].y;
            pos=i;
        }
        else if(minn==a[i].x+a[i].y){
            if(a[pos].x>a[i].x) pos=i;
        }
    }
    ll ans=0,sum=0,num=0;
    ll cnt=num+(m-sum)/minn*2;
    ll tmp=(m-sum)%minn;
    if(tmp>a[pos].x) cnt++;
    ans=max(ans,cnt);
    for(int i=1;i<=n;i++){
        if(i!=pos) sum+=a[i].x,num++;
        if(m<sum) break;
        ll cnt=num+(m-sum)/minn*2;
        ll tmp=(m-sum)%minn;
        if(tmp>a[pos].x) cnt++;
        ans=max(ans,cnt);
    }
    cout<<ans;
    return 0;
}