#include<bits/stdc++.h>
#define pii pair<ll,int>
using namespace std;
typedef long long ll;
const int N=1e5+10,M=3e5+10;
const ll inf=1e18;
vector<pair<int,ll> > g[N];
int n,m,k,q;
ll dis[N];int from[N];
bool vis[N];
void dijk(){
    priority_queue<pii,vector<pii>,greater<pii> >q;
    fill(dis+1,dis+n+1,inf);
    fill(vis+1,vis+n+1,0);
    for(int i=1;i<=k;i++){
        q.push({0,i});
        dis[i]=0;from[i]=i;
    }
    while(!q.empty()){
        int u=q.top().second;q.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(auto d:g[u]){
            int v=d.first;ll val=d.second;
            if(dis[v]>dis[u]+val){
                dis[v]=dis[u]+val;
                from[v]=from[u];
                q.push({dis[v],v});
            }
        }
    }
}
struct edge{
    int u,v;ll w;
    bool operator <(const edge &x) const{
        return w<x.w;
    }
}e[M*2];
int cnt,fa[N];
vector<pair<int,ll> > gt[N];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
void merge(int u,int v){
    u=find(u);v=find(v);
    fa[u]=v;
}
int dep[N],f[20][N];
ll st[20][N];
void dfs(int u,int father,ll inval){
    dep[u]=dep[father]+1;
    f[0][u]=father;
    st[0][u]=inval;
    for(int j=1;j<20;j++){
        f[j][u]=f[j-1][f[j-1][u]];
        st[j][u]=max(st[j-1][f[j-1][u]],st[j-1][u]);
    }
    for(auto d:gt[u]){
        int v=d.first;
        if(v==father) continue;
        dfs(v,u,d.second);
    }
    return;
}
ll lca(int u,int v){
    if(u==v) return 0;
    if(dep[u]>dep[v]) swap(u,v);
    ll ans=0;
    for(int j=19;j>=0;j--){
        if(dep[f[j][v]]>=dep[u]) ans=max(ans,st[j][v]),v=f[j][v];
    }
    if(u==v) return ans;
    for(int j=19;j>=0;j--){
        if(f[j][u]!=f[j][v]){
            ans=max(ans,max(st[j][u],st[j][v]));
            u=f[j][u];v=f[j][v];
        }
    }
    return max(ans,max(st[0][u],st[0][v]));
}
int main(){
    freopen("recharge.in","r",stdin);
    freopen("recharge.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m>>k>>q;
    for(int i=1;i<=m;i++){
        int u,v,w;cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    dijk();
    for(int u=1;u<=n;u++){
        for(auto d:g[u]){
            int v=d.first;ll val=d.second;
            if(from[u]==from[v]) continue;
            e[++cnt]={from[u],from[v],dis[u]+dis[v]+val};
        }
    }
    sort(e+1,e+cnt+1);
    int tot=0;
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=1;i<=cnt;i++){
        int u=e[i].u,v=e[i].v;ll w=e[i].w;
        if(find(u)==find(v))continue;
        else{
            merge(u,v),tot++;
            gt[u].push_back({v,w});
            gt[v].push_back({u,w});
            if(tot==k-1) break;
        }
    }
    dfs(1,1,0);
    for(int i=1;i<=q;i++){
        int a,b;cin>>a>>b;
        cout<<lca(a,b)<<"\n";
    }
    return 0;
}