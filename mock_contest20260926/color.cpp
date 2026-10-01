#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10;
const ll mod=998244353;
ll f[N];
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    for(int i=1;i<N;i++) f[i]=(f[i-1]+1)*(f[i-1]+1)%mod;
    while(t--){
        int n;string s;
        cin>>n>>s;
        string t;
        while(t.size()+s.size()<n) t.push_back('0');
        t+=s;
        for(int i=int(t.size())-1;i>=0;i--){
            if(t[i]=='0') t[i]='1';
            else{
                t[i]='0';break;
            }
        }
        ll ans=1;
        for(int i=n;i>=2;i--){
            ans=(ans+1)*(f[n-i+t[i-1]-'0']+1)%mod;
        }
        cout<<ans<<"\n";
    }
    return 0;
}