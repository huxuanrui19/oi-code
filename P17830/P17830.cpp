#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10,M=3e5+10;
const ll inf=1e18,mod=1e9+7;
int n,m,a[N],p[M],cnt[N],ans[M];
int main(){
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) p[a[i]]=i;
    for(int i=1;i<=n;i++){
        cnt[i]++;
        cnt[p[a[i]]+1]+=cnt[i];
    }
    for(int i=1;i<=n;i++) ans[a[i]]+=cnt[i];
    for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
    return 0;
}