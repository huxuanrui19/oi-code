#include<bits/stdc++.h>
#define pii pair<ll,int>
using namespace std;
typedef long long ll;
const int N=1e5+10;
const ll inf=1e18;
vector<pii> g[N];
int n,m,k,vis[N],pos[N],from[N];
ll ans,dis[N];
void dijk(){
    fill(vis+1,vis+n+1,0);
    fill(dis+1,dis+n+1,inf);
    fill(from+1,from+n+1,0);
    priority_queue<pii,vector<pii>,greater<pii> > q;
    ans=inf;
    for(int i=1;i<=k;i++){
        dis[pos[i]]=0;
        from[pos[i]]=pos[i];
        q.push({0,pos[i]});
    }
    while(!q.empty()){
        pii now=q.top();
        ll d=now.first;
        int u=now.second;
        q.pop();
        if(vis[u]==1) continue;
        vis[u]=1;
        for(pii e:g[u]){
            ll w=e.first;
            int v=e.second;
            if(from[v]!=0&&from[u]!=from[v]){
                ans=min(ans,dis[u]+dis[v]+w);
            }
            if(dis[v]>d+w){
                dis[v]=d+w;
                from[v]=from[u];
                q.push({dis[v],v});
            }
        }
    }
}
void cl(){for(int i=1;i<=n;i++) g[i].clear();}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        cin>>n>>m>>k;
        for(int i=1;i<=m;i++){
            int u,v,a;cin>>u>>v>>a;
            g[u].push_back({a,v});
            g[v].push_back({a,u});
        }
        for(int i=1;i<=k;i++) cin>>pos[i];
        dijk();
        cout<<ans<<"\n";
        cl();
    }
    return 0;
}
