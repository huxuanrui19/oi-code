#include <bits/stdc++.h>
#define lll __int128
#define pii pair<lll,lll>
using namespace std;
typedef long long ll;
const int N=5e5+10;
const ll maxn=1e18,mod=1e9+7;
ll n,a[N<<1];
bool check(ll x){
    lll up=x;
    stack<pii> st;
    for(int i=1;i<=n*2;i++){
        if(a[i]<=up){
            up+=a[i];
            while(!st.empty()&&st.top().first<=up){
                up+=st.top().second;
                st.pop();
            }
        }else{
            st.push({lll(a[i]),lll(up-x+a[i])});
            up=x;
        }
    }
    return st.empty();
}
int main(){
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) a[i+n]=a[i];
    ll l=0,r=1e13+10,ans=0;
    while(l<=r){
        ll mid=(l+r)>>1;
        if(check(mid)) r=mid-1,ans=mid;
        else l=mid+1;
    }
    cout<<ans;
    return 0;
}