#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
const ll inf=1e18,mod=1e9+7;
ll qp(ll n,ll k){
    ll sum=1;
    while(k){
        if(k&1) sum=sum*n%mod;
        n=n*n%mod;
        k>>=1;
    }
    return sum;
}
int main(){
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t;cin>>t;
    while(t--){
        int n,k;cin>>n>>k;
        string s;cin>>s;
        s=" "+s;
        int pos=0;
        for(int i=1;i<=n;i++){
            if(s[i]=='1') pos=i;
        }
        if(n-pos<k) cout<<"0\n";
        else cout<<(qp(2,k)*(qp(2,n-pos-k+1)-1)%mod)<<"\n";
    }
    return 0;
}