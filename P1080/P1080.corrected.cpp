#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e3+10;
ll n,aa,bb;
struct node{
    ll a,b;
    bool operator <(const node &x)const{
        if(a*b!=x.a*x.b) return (a*b)<(x.a*x.b);
        else return a<x.a;
    }
}arr[N];
struct Bint{
    int len,a[N<<3];
    void init(){
        memset(a,0,sizeof(a));
        len=0;
    }
    Bint operator *(const ll x)const{
        ll cnt=0;Bint b;b.init();
        for(int i=1;i<=len;i++){
            b.a[i]=(a[i]*x+cnt)%10;
            cnt=(a[i]*x+cnt)/10;
        }
        ll l=len;
        while(cnt!=0){
            b.a[++l]=cnt%10;
            cnt/=10;
        }
        b.len=l;
        return b;
    }
    Bint operator /(const ll x)const{
        ll cnt=0;Bint b;b.init();
        ll l=0;
        for(int i=len;i>=1;i--){
            cnt=cnt*10+a[i];
            b.a[++l]=cnt/x;
            cnt%=x;
        }
        reverse(b.a+1,b.a+l+1);
        while(l>0 && b.a[l]==0) l--;
        b.len=l;
        return b;
    }
};
inline Bint get_max(const Bint &x,const Bint &y){
    if(x.len!=y.len) return x.len<y.len ? y : x;
    for(int i=x.len;i>=1;i--){
        if(x.a[i]!=y.a[i]) return x.a[i]<y.a[i] ? y : x;
    }
    return x;
}
int main(){
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>aa>>bb;
    for(int i=1;i<=n;i++) cin>>arr[i].a>>arr[i].b;
    sort(arr+1,arr+n+1);
    Bint ans;ans.init();
    while(aa){
        ans.a[++ans.len]=aa%10;
        aa/=10;
    }
    Bint cnt;cnt.init();
    for(int i=1;i<=n;i++){
        cnt=get_max(cnt,ans/arr[i].b);
        ans=ans*arr[i].a;
    }
    if(cnt.len==0) cout<<"0";
    else for(int i=cnt.len;i>=1;i--) cout<<cnt.a[i];
    return 0;
}
