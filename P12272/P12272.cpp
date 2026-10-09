#include<bits/stdc++.h>
#define gcd __gcd
using namespace std;
typedef long long ll;
const int N=1e5+10;
const ll maxn=1e18,mod=998244353;
ll phi(ll p){
    ll ans=p;
    for(ll i=2;i*i<=p;i++){
        if(p%i==0){
            ans=ans/i*(i-1);
            while(p%i==0) p/=i;
        }
    }
    if(p>1) ans=ans/p*(p-1);
    return ans;
}
inline ll qp(ll n,ll k,ll m){
    __int128 sum=1,nn=n;
    while(k){
        if(k&1) sum=sum*nn%m;
        nn=nn*nn%m;
        k>>=1;
    }
    return (ll)sum;
}
int main(){
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll n;cin>>n;
    ll sum=maxn,num=0;
    if(n%10==0){
        cout<<"-1";
        return 0;
    }
    for(ll i=1;i<=9;i++){
        ll m=9*n/gcd(9*n,i);
        if(m%2==0||m%5==0) continue;
        ll p=phi(m),len=maxn;
        for(ll j=1;j*j<=p;j++){
            if(p%j==0){
                if(qp(10,j,m)==1) len=min(len,j);
                if(qp(10,p/j,m)==1) len=min(len,p/j);
            }
        }
        if(len<sum) sum=len,num=i;
    }
    if(sum==maxn) cout<<"-1";
    else{
        __int128 ans=num;
        ans=ans*(qp(10,sum,mod)-1)%((__int128)mod);
        ans=ans*qp(9,mod-2,mod)%((__int128)mod);
        cout<<(ll)ans;
    }
    return 0;
}