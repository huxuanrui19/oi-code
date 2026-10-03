#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2500+10;
int n;
struct node{
    ll x,y;
    bool operator <(const node &tmp){
        if(x!=tmp.x) return x<tmp.x;
        else return y<tmp.y;
    }
}a[N];
int main(){
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i].x>>a[i].y;
    sort(a+1,a+n+1);
    ll ans=1;
    for(int i=1;i<=n;i++){
        ll l=0,r=0;
        for(int j=1;j<=i;j++){
            if(a[j].y>=a[i].y) l++;
            if(a[j].y<=a[i].y) r++;
        }
        ans+=(l*r);
    }
    cout<<ans;
    return 0;
}