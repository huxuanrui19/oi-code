#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2005;
const ll INF = (ll)1e18;
struct ZeroEdge{
    int u, v;
    ll w;
};
int n, m;
int U[N], V[N];
ll Len[N], Cost[N];
int fa[N];
bool chosen[N];
ll Ans;
vector<pair<int, ll> > G[N];

int find(int x){
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

ll dis[N];
bool vis[N];
// 最短路：原标程用线段树堆，这里换成普通的堆优化 Dijkstra，效果相同
ll getdis(int s, int t){
    for(int i = 1; i <= n; i++){
        dis[i] = INF;
        vis[i] = false;
    }
    priority_queue<pair<ll, int>, vector<pair<ll, int> >, greater<pair<ll, int> > > pq;
    dis[s] = 0;
    pq.push(make_pair(0, s));
    while(!pq.empty()){
        ll d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if(vis[u]) continue;
        vis[u] = true;
        for(int i = 0; i < (int)G[u].size(); i++){
            int v = G[u][i].first;
            ll w = G[u][i].second;
            if(!vis[v] && dis[u] + w < dis[v]){
                dis[v] = dis[u] + w;
                pq.push(make_pair(dis[v], v));
            }
        }
    }
    return dis[t];
}

int main(){
    freopen("upkeep.in","r",stdin);
    freopen("upkeep.out","w",stdout);
    cin >> n >> m;
    int cnt = 0;
    vector<ZeroEdge> es;
    for(int i = 1; i <= n; i++) fa[i] = i;
    for(int i = 1; i <= m; i++){
        cin >> U[i] >> V[i] >> Len[i] >> Cost[i];
        if(Len[i] == 0){
            es.push_back((ZeroEdge){U[i], V[i], Cost[i]});
            chosen[i] = true;
        }
        else cnt++;
    }
    sort(es.begin(), es.end(), [](const ZeroEdge &x, const ZeroEdge &y){
        return x.w < y.w;
    });
    for(int i = 0; i < (int)es.size(); i++){
        int fu = find(es[i].u), fv = find(es[i].v);
        if(fu == fv) continue;
        fa[fu] = fv;
        Ans += es[i].w;
    }
    for(int t = 1; t <= cnt; t++){
        int pos = 0;
        for(int i = 1; i <= m; i++) if(!chosen[i]){
            if(!pos) pos = i;
            else if(Len[i] < Len[pos]) pos = i;
            else if(Len[i] == Len[pos] && Cost[i] < Cost[pos]) pos = i;
        }
        chosen[pos] = true;
        int nu = find(U[pos]), nv = find(V[pos]);
        if(Len[pos] < getdis(nu, nv)){
            G[nu].push_back(make_pair(nv, Len[pos]));
            G[nv].push_back(make_pair(nu, Len[pos]));
            Ans += Cost[pos];
        }
    }
    cout << Ans;
    return 0;
}
