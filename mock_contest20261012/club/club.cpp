#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
const ll inf=1e18,mod=1e9+7;
ll n,sum[3],a[N][3],id[N],used[N];
int main(){
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t;cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i][0]>>a[i][1]>>a[i][2];
        for(int i=1;i<=n;i++){
            ll maxn=a[i][0],idx=0;
            for(int j=1;j<=2;j++){
                if(maxn<a[i][j]){
                    maxn=a[i][j];
                    idx=j;
                }
                id[i]=idx;
            }
        }
        for(int i=0;i<3;i++) sum[i]=0;
        for(int i=1;i<=n;i++) sum[id[i]]++;
        int flag=-1;
        for(int i=0;i<=2;i++){
            if(sum[i]>n/2) flag=i;
        }
        ll ans=0;for(int i=1;i<=n;i++) ans+=max({a[i][0],a[i][1],a[i][2]});
        if(flag==-1) cout<<ans<<"\n";
        else{
            priority_queue<pair<ll,int> > p;
            for(int i=1;i<=n;i++){
                if(id[i]!=flag) continue;
                for(int j=0;j<3;j++){
                    if(j==flag) continue;
                    else p.push({a[i][j]-a[i][flag],i});
                }
            }
            ll sum=0;
            for(int i=1;i<=n;i++){
                if(id[i]==flag) sum++;
            }
            while(sum>n/2){
                int u=p.top().second;ll w=p.top().first;p.pop();
                if(used[u]) continue;
                else ans+=w,used[u]=1;
                sum--;
            }
            cout<<ans<<"\n";
        }
        for(int i=1;i<=n;i++) used[i]=0;
    }
    return 0;
}