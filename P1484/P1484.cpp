#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3e5+10;
const ll inf=1e18,mod=1e9+7;
ll n,k,a[N],vis[N];
ll val[N],lst[N],nxt[N];
int main(){
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n>>k;for(int i=1;i<=n;i++) cin>>a[i];
    priority_queue<pair<ll,int> > q;
    val[0]=val[n+1]=-inf; // 边界哨兵取 -inf，保证“反悔”不会在边界上凭空多选一个元素
    for(int i=1;i<=n;i++){
        val[i]=a[i];
        lst[i]=i-1;
        nxt[i]=i+1;
    }
    for(int i=1;i<=n;i++){
        q.push({a[i],i});
    }
    ll cnt=0,ans=0,res=0;
    while(cnt<k){
        while(vis[q.top().second]) q.pop();
        auto u=q.top();q.pop();
        vis[lst[u.second]]=vis[nxt[u.second]]=1;
        ans+=u.first;
        u.first=-u.first+val[lst[u.second]]+val[nxt[u.second]];
        val[u.second]=u.first;
        nxt[lst[lst[u.second]]]=u.second;
        lst[u.second]=lst[lst[u.second]];
        lst[nxt[nxt[u.second]]]=u.second;
        nxt[u.second]=nxt[nxt[u.second]];
        q.push(u);
        cnt++;
        res=max(res,ans);
    }
    cout<<res<<"\n";
    return 0;
}