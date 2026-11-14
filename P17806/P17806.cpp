#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
const ll mod=1e9+7;
ll qp(ll n,ll k){
    ll sum=1;
    while(k){
        if(k&1) sum=sum*n%mod;
        n=n*n%mod;k>>=1;
    }
    return sum;
}
int main(){
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        string s;cin>>s;
        ll n=0;
        for(auto ch:s) n+=(ch=='1');
        ll ans=0,j=0;
        for(int i=1;i<=n;i++){
            while(s[j]!='1'&&(j+1)<(int)s.size()) j++;
            ans=(ans+qp(3,n-i)*qp(2,s.size()-j-1-(n-i))%mod)%mod;
            j++;
        }
        cout<<(ans+1)<<"\n";
    }
    return 0;
}