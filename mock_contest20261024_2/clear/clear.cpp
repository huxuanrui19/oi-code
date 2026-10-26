#include<bits/stdc++.h>
#define pii pair<ll,int>
using namespace std;
typedef long long ll;
const int N=2e5+10;
const ll maxn=1e18,mod=1e9+7;
ll n,m,c[N],d[N],vis[N];
vector<pii> g[N];
struct node{
    ll d,c,idx;
    bool operator >(const node &x) const{
        if(d!=x.d) return d>x.d;
        if(c!=x.c) return c<x.c;
    }
};
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    ll maxn=0;
    for(int i=1;i<=m;i++){
        ll u,v,dd,cc;cin>>u>>v>>cc>>dd;
        c[u]+=cc,c[v]+=cc;
        d[u]+=dd,d[v]+=dd;
        g[u].push_back({dd,v});
        g[v].push_back({dd,u});
        maxn+=dd;
    }
    ll del=0,ans=0;
    priority_queue<node,vector<node>,greater<node> > q;
    for(int i=1;i<=n;i++) q.push({d[i],c[i],i});
    while(!q.empty()){
        int u=q.top().idx;q.pop();
        if(vis[u]) continue;
        vis[u]=1;
        ans=max(ans,d[u]-del);
        del+=c[u]-d[u];
        for(auto x:g[u]){
            int v=x.second;
            d[v]-=x.first;
            if(!vis[v]) q.push((node){d[v],c[v],v});
        }
    }
    cout<<ans;
    return 0;
}
