#include<bits/stdc++.h>
#define pii pair<ll,int>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N=1e5+10;
ll n,a[N],b[N],c[N],t[N],maxn[N],vis[N];
vector<int> g[N];
void dfs1(int u,int fa){
    maxn[u]=max(maxn[u],t[u]);
    for(auto d:g[u]){
        if(d==fa) continue;
        dfs1(d,u);
        maxn[u]=max(maxn[u],maxn[d]+1);
    }
    return;
}
int main(){
    //freopen("tree/tree2.in","r",stdin);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i]>>b[i]>>c[i];
    for(int i=1;i<n;i++){
        int u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=1;i<=n;i++) t[i]=ceil((ld)(a[i])/b[i]);
    dfs1(1,0);
    priority_queue<pii,vector<pii>,less<pii> > q;
    q.push({maxn[1],1});
    ll sum=0,ans=0;
    while(!q.empty()){
        int u=q.top().second;q.pop();
        if(vis[u]) continue;
        vis[u]=1;
        sum++;
        ans=max(ans,sum-1+t[u]);
        for(auto d:g[u]){
            if(!vis[d]){
                q.push({maxn[d],d});
            }
        }
    }
    cout<<ans;
    return 0;
}
