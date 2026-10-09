#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e7+10;
const ll maxn=1e18,mod=1e9+7;
int n;ll a[N],e[N];
void init(){
    ll x,y,z,m0,m1,c0,c1;
    cin>>x>>y>>z>>m0>>m1>>c0>>c1;
    a[0]=c0;a[1]=c1;
    for(int i=2;i<n;i++) a[i]=(a[i-1]*x+a[i-2]*y+z)%(i%2==0?m0:m1)+1;
    return;
}
ll rem[N];
int main(){
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n;init();
    for(int i=0;i<n;i+=2) rem[i]=a[i];
    ll ans=0;
    for(int i=1;i<n;i+=2){
        ll need=a[i];
        ll lst=0;
        ll s=i-1;
        while(need>0&&s>=0){
            if(rem[s]==0){
                s=s-2;continue;
            }
            long long d=min(rem[s],need);
            rem[s]-=d;need-=d;
            if(rem[s]==0){
                ans=ans+(d-1);
                ll val=1;
                if(s>=1) val=val+e[s-1];
                ans+=val;
                lst=val;s-=2;
            }
            else{
                ans+=d;lst=1;
            }
        }
        if(need>0) lst=0;
        e[i]=lst;
    }
    cout<<ans;
    return 0;
}