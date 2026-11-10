#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10,M=20;
const ll inf=1e18,mod=1e9+7;
ll n,k,a[N],b[N],c[N];
int main(){
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    for(int i=1;i<=n;i++) c[i]=b[i]-a[i];
    for(int i=1;i<=n;i++){
        if(c[i]<0){
            cout<<"-1\n";
            return 0;
        }
    }
    ll ans=0,sum=0;
    deque<pair<int,ll> > st;
    for(int i=1;i<=n;i++){
        while(!st.empty()&&st.front().first<i) sum-=st.front().second,st.pop_front();
        if(sum<c[i]){
            ans+=c[i]-sum;
            st.push_back({i+k-1,c[i]-sum});sum=c[i];
        }
        else if(sum>c[i]){
            while(!st.empty()&&sum>c[i]){
                ll d=min(st.front().second,sum-c[i]);
                st.front().second-=d;sum-=d;
                if(st.front().second==0) st.pop_front();
            }
        }
    }
    cout<<ans;
    return 0;
}