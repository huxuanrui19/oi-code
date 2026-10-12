#include <bits/stdc++.h>
#define pii pair<ll,int>
using namespace std;
typedef long long ll;
const int N=2e3+10;
const ll inf=1e18,mod=1e9+7;
struct edge{
    int u,v;ll w;
    bool operator <(const edge &x) const{
        return w<x.w;
    }
};
int n,m,cnt;
int U[N],V[N];
ll len[N],cost[N];
bool used[N];
vector<pair<int,ll> >g[N];

int fa[N];
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
inline void merge(int u,int v){
    u=find(u);v=find(v);
    fa[u]=v;
}

ll dis[N];
bool vis[N];
ll dijk(int s,int t){
    for(int i=1;i<=n;i++) vis[i]=0,dis[i]=inf;
    dis[s]=0;
    priority_queue<pii,vector<pii>,greater<pii> > q;
    q.push({0,s});
    while(!q.empty()){
        int u=q.top().second;q.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(auto d:g[u]){
            int v=d.first;ll w=d.second;
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                if(!vis[v]) q.push({dis[v],v});
            }
        }
    }
    return dis[t];
}

ll ans=0;
int main(){
    freopen("upkeep.in","r",stdin);
    freopen("upkeep.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n>>m;
    vector<edge> es;
    for(int i=1;i<=m;i++){
        cin>>U[i]>>V[i]>>len[i]>>cost[i];
        if(len[i]==0){
            es.push_back((edge){U[i],V[i],cost[i]});
            used[i]=true;
        }
        else cnt++;
    }
    sort(es.begin(),es.end());
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=0;i<(int)es.size();i++){
        int u=es[i].u,v=es[i].v;
        if(find(u)==find(v)) continue;
        merge(u,v);
        ans+=es[i].w;
    }
    for(int t=1;t<=cnt;t++){
        int pos=0;
        for(int i=1;i<=m;i++){
            if(!used[i]){
                if(!pos) pos=i;
                else if(len[i]<len[pos]) pos=i;
                else if(len[i]==len[pos]&&cost[i]<cost[pos]) pos=i;
            }
        }
        used[pos]=true;
        int nu=find(U[pos]),nv=find(V[pos]);
        if(len[pos]<dijk(nu,nv)){
            g[nu].push_back({nv,len[pos]});
            g[nv].push_back({nu,len[pos]});
            ans+=cost[pos];
        }
    }
    cout<<ans;
    return 0;
}