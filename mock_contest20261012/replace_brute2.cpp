#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
const ll base=211,mod=1568873333;
int n,q;
string s1[N],s2[N];
struct Hash{
    ll ha;
    void init(string s){
        ha=0;
        for(int i=0;i<s.size();i++){
            ha=ha*base%mod;
            ha=(ha+int(s[i]))%mod;
        }
    }
};
struct node{
    ll pre,lst;
    ll x1,x2,len;
};
unordered_map<pair<ll,ll>,vector<node> > mp;

ll pw[N],inv[N];
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
    pw[0]=1;
    for(int i=1;i<N;i++) pw[i]=pw[i-1]*base%mod;
    inv[N-1]=qp(pw[N-1],mod-2);
    for(int i=N-2;i>=0;i--) inv[i]=inv[i+1]*base%mod;
    
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>s1[i]>>s2[i];
    for(int i=1;i<=n;i++){
        string core1,core2;
        int l=-1,r=-1;
        for(int j=0;j<s1[i].size();j++){
            if(s1[i][j]!=s2[i][j]){
                l=j;break;
            }
        }
        for(int j=s1[i].size()-1;j>=0;j--){
            if(s1[i][j]!=s2[i][j]){
                r=j;break;
            }
        }
        if(l<0){
            Hash h1;h1.init(s1[i]);
            mp[{0,0}].push_back((node){h1.ha,h1.ha,0,0,s1[i].size()});
        }
        else{
            Hash h1,h2;
            h1.init(s1[i].substr(l,r-l+1));
            h2.init(s2[i].substr(l,r-l+1));
            Hash pre,nxt;
            pre.init(s1[i].substr(0,l));
            nxt.init(s1[i].substr(r+1,n-r-1));
            mp[{h1.ha,h2.ha}].push_back((node){pre.ha,nxt.ha,l,r,s1[i].size()});
        }
    }

    while(q--){
        string t1,t2;cin>>t1>>t2;
        if(t1.size()!=t2.size()){
            cout<<"0\n";
            continue;
        }
        int l=-1,r=-1;
        for(int i=0;i<t1.size();i++){
            if(t1[i]!=t2[i]){
                l=i;break;
            }
        }
        for(int i=t1.size()-1;i>=0;i--){
            if(t1[i]!=t2[i]){
                r=i;break;
            }
        }
        pair<ll,ll> core;
        if(l==-1&&r==-1) core={0,0};
        else{
            Hash h1,h2;
            h1.init(t1.substr(l,r-l+1));
            h2.init(t2.substr(l,r-l+1));
            core={h1.ha,h2.ha};
        }
        vector<ll> v;
        v.push_back(ll(t1[0]));
        for(int i=1;i<t1.size();i++){
            ll u=v.back();
            u=u*base%mod;
            u=(u+ll(t1[i]))%mod;
            v.push_back(u);
        }
        for(auto d:mp[core]){
            ll hs1=
        }
    }
    return 0;
}