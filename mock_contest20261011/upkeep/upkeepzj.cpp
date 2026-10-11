#include <bits/stdc++.h>
#define pii pair<ll,int>
using namespace std;
typedef long long ll;
const int N=2e3+10;
const ll inf=1e18,mod=1e9+7;
struct to{
    int v;
    ll l,c;
};
struct edge{
    int u,v;
    ll l,c;
};

vector<to> g[N];
int n,m;    //graph

bool flag[N],vis[N];
ll dis[N][N];   //dij

int bg,tl,q[N];
vector<int> pt;
vector<edge> ed;
bool used[N];
ll ans=0;
void get_min(int s){
    bg=tl=0;
    q[++tl]=s;
    pt.clear();ed.clear();
    while(bg<tl){
        int u=q[tl--];
        if(flag[u]) continue;
        flag[u]=1;
        pt.push_back(u);
        for(auto d:g[u]){
            int v=d.v;
            if(!flag[v]) q[++tl]=v;
        }
    }
    for(auto d:pt){
        dijk(d);
    }
    for(auto u:pt){
        for(auto x:g[u]){
            if(x.l==dis[u][x.v]) ed.push_back({u,x.v,x.l,x.c});
        }
    }
    int i=0;
    for(auto e:ed){
        used[++i]=1;
    }
    for(auto e:ed){
        int u=e.u,v=e.v,l=e.l;
        if(l==0){
            //for(auto )
        }
        for(auto w:pt){
            if(w==u||w==v) continue;
            //
        }
    }
}

void dijk(int s){
    priority_queue<pii,vector<pii>,greater<pii> > q;
    for(auto d:pt) vis[d]=0,dis[s][d]=inf;
    q.push({0,s});dis[s][s]=0;
    while(!q.empty()){
        int u=q.top().second;q.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(auto d:g[u]){
            int v=d.v;
            if(dis[s][v]>dis[s][u]+d.l){
                dis[s][v]=dis[s][u]+d.l;
                if(!vis[v]) q.push({dis[s][v],v});
            }
        }
    }
}

int main(){
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v,l,c;
        cin>>u>>v>>l>>c;
        g[u].push_back({v,l,c});
        g[v].push_back({u,l,c});
    }
    for(int i=1;i<=n;i++){
        if(flag[i]==0){
            get_min(i);
        }
    }
    return 0;
}