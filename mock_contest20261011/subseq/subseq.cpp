#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e4+10,M=30,Q=2e5+10;
const ll inf=1e18,mod=1e9+7;
int n,k,q,a[N];
struct query{
    int l,r;
    ll ans;
    int idx;
    bool operator <(const query &x) const{
        return idx<x.idx;
    }
}arr[Q];
unordered_map<int,ll> mp[N];
ll dp[M],maxn[N];
int main(){
    freopen("subseq.in","r",stdin);
    freopen("subseq.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    cin>>q;
    for(int i=1;i<=q;i++){
        cin>>arr[i].l>>arr[i].r;
        arr[i].idx=i;
        mp[arr[i].l][arr[i].r]=0;
        maxn[arr[i].l]=max(maxn[arr[i].l],(ll)arr[i].r);
    }
    for(int i=1;i<=n;i++){
        if(mp[i].size()==0) continue;
        dp[0]=1;
        for(int t=1;t<=k;t++) dp[t]=0;
        for(int j=i;j<=n;j++){
            if(j>maxn[i]) break;
            ll sum=0;
            for(int t=0;t<=a[j];t++){
                sum=(sum+dp[t])%mod;
            }
            dp[a[j]]=(dp[a[j]]+sum)%mod;
            if(mp[i].count(j)){
                for(int t=0;t<=k;t++) mp[i][j]=(mp[i][j]+dp[t])%mod;
            }
        }
    }
    for(int i=1;i<=q;i++) arr[i].ans=mp[arr[i].l][arr[i].r];
    sort(arr+1,arr+q+1);
    for(int i=1;i<=q;i++) cout<<arr[i].ans<<"\n";
    return 0;
}