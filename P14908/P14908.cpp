#include<bits/stdc++.h>
#define ls(p) (p)<<1
#define rs(p) (p)<<1|1
#define lowbit(x) (x)&-(x)
#define pii pair<int,int>
#define debug(x) cerr<<"x = "<<x<<"\n"
using namespace std;

template <typename T>
void read(T &x){
    x=0;int f=1;char ch=getchar();
    while(!isdigit(ch)){
        if(ch=='-') f*=-1;
        ch=getchar();
    }
    while(isdigit(ch)){
        x=(x<<1)+(x<<3)+(ch&15);
        ch=getchar();
    }
    x*=f;
}

typedef long long ll;
const int N=1e6+10;
ll n,k,sum,a[N];
void solve(){
    read(n);read(k);sum=0;
    for(int i=1;i<=n;i++) read(a[i]);
    for(int i=1;i<=n;i++) sum+=a[i];
    k%=n;
    if(k==0){
        for(int i=1;i<=n;i++){
            if(a[i]!=a[1]){
                cout<<"poor monkeys\n";
                return;
            }
        }
        cout<<"0\n";
    }
    else{
        ll ans=(sum-k*a[1]+n-k-1)/(n-k);
        ans=max(ans,a[n]);
        for(ll i=ans;i<=ans+n;i++){
            if((i*n-sum)%k==0){
                cout<<((n*i-sum)/k)<<"\n";
                return;
            }
        }
    }
    cout<<"poor monkeys\n";
    return;
}
int main(){
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);cerr.tie(0);
    int t;read(t);
    while(t--){
        solve();
    }
    return 0;
}