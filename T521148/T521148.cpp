#include <bits/stdc++.h>
#define pii pair<ll,int>
using namespace std;
typedef long long ll;
const int N=1e5+10;
const ll maxn=1e18,mod=1e9+7;
ll n,m,lt[N],rt[N],a[N],sum[N];
bool check(ll h){
    for(int i=1;i<=n;i++) if(a[i]>=h) return 1;
    priority_queue<pii,vector<pii>,greater<pii> > q;
    for(int i=1;i<=n;i++){
        if(i==1) lt[i]=0;
        else{
            int j=lt[i-1];
            while(!q.empty()&&q.top().first<=i-h){
                j=max(j,q.top().second);
                q.pop();
            }
            lt[i]=j;
        }
        q.push({i-a[i],i});
    }
    priority_queue<pii,vector<pii>,less<pii> > p;
    for(int i=n;i>=1;i--){
        if(i==n) rt[i]=n+1;
        else{
            int j=rt[i+1];
            while(!p.empty()&&p.top().first>=h+i){
                j=min(j,p.top().second);
                p.pop();
            }
            rt[i]=j;
        }
        p.push({i+a[i],i});
    }
    ll ans=1e18;
    for(int i=2;i<n;i++){
        if(lt[i]==0||rt[i]==n+1) continue;
        else{
            ll cnt=sum[rt[i]-1]-sum[lt[i]];
            ll cur=0;
            if(lt[i]+1<=i) cur+=(h+h-(i-lt[i]-1))*(i-lt[i])/2;
            if(i+1<=rt[i]-1) cur+=(h-1+h-1-(rt[i]-1-i-1))*(rt[i]-i-1)/2;
            ans=min(ans,cur-cnt);
        }
    }
    return ans<=m;
}
int main(){
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    ll l=1,r=1e10,ans=0;
    while(l<=r){
        ll mid=(l+r)>>1;
        if(check(mid)) l=mid+1,ans=mid;
        else r=mid-1;
    }
    cout<<ans;
    return 0;
}