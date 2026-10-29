#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+10;
const ll base1=211,mod1=1500000001;
const ll base2=233,mod2=1500000233;
ll n,pw1[N],pw2[N];
string s;
map<pair<ll,ll> ,ll> mp;
int main(){
    //freopen("game\\game3.in","r",stdin);
    //freopen(".out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n>>s;s=" "+s;
    pw1[0]=1;for(int i=1;i<=n;i++) pw1[i]=pw1[i-1]*base1%mod1;
    pw2[0]=1;for(int i=1;i<=n;i++) pw2[i]=pw2[i-1]*base2%mod2;
    ll hh1=0,hh2=0;
    stack<char> st;
    mp[{0,0}]++;
    for(int i=1;i<=n;i++){
        if(st.empty()){
            st.push(s[i]);
            hh1=(hh1+pw1[st.size()]*(s[i]-'a'+1))%mod1;
            hh2=(hh2+pw2[st.size()]*(s[i]-'a'+1))%mod2;
        }
        else if(st.top()==s[i]){
            st.pop();
            hh1=(hh1-pw1[st.size()+1]*(s[i]-'a'+1)%mod1+mod1)%mod1;
            hh2=(hh2-pw2[st.size()+1]*(s[i]-'a'+1)%mod2+mod2)%mod2;
        }
        else{
            st.push(s[i]);
            hh1=(hh1+pw1[st.size()]*(s[i]-'a'+1))%mod1;
            hh2=(hh2+pw2[st.size()]*(s[i]-'a'+1))%mod2;
        }
        mp[{hh1,hh2}]++;
    }
    ll ans=0;
    for(auto d:mp){
        ll x=d.second;
        ans+=x*(x-1)/2;
    }
    cout<<ans;
    return 0;
}