#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;

int main(){
    freopen("stone.in","r",stdin);
    freopen("stone.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        ll n,p,q;cin>>n>>p>>q;
        ll ans=0;
        if(p==0) cout<<"0\n";
        else if(q==0) cout<<(n%2)*p<<"\n";
        else if(n%2==0){
            ll maxn=n/2;
            maxn=min(maxn,(q+p)/(4*p));
            ans=(maxn*2+1)*(maxn*2)/2*p+(n-maxn*2)/2*q;
            cout<<ans<<"\n";
        }
        else if(n%2==1){
            ll maxn=n/2;
            maxn=min(maxn,(q-p)/(4*p));
            if(maxn<0) maxn=0;
            ans=(2*maxn+1)*(maxn*2+2)/2*p+(n-maxn*2-1)/2*q;
            cout<<ans<<"\n";
        }
    }
    return 0;
}