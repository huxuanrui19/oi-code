#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10,M=1e6+10;
int n,a[N],pos[M];
ll dp[N],sum[N];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++){
            if(a[i]==a[i-1]) sum[i]=sum[i-1]+a[i];
            else sum[i]=sum[i-1];
        }
        for(int i=1;i<=n;i++){
            dp[i]=dp[i-1];
            if(pos[a[i]]){
                int l=pos[a[i]];
                ll num=dp[l+1]+a[i];
                if(i-l-1>=2) num+=sum[i-1]-sum[l+1];
                dp[i]=max(dp[i],num);
            }
            pos[a[i]]=i;
        }
        cout<<dp[n]<<"\n";
        for(int i=1;i<=n;i++) pos[a[i]]=0;
    }
    return 0;
}
