#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e3+10;
const ll inf=1e18,mod=1e9+7;
int n,m;
struct edge{
    int u,v;
    ll l,c;
    bool operator <(const edge &x) const{
        return c<x.c;
    }
}e[N],et[N];
struct to{
    int v;
    ll l,c;
};
vector<to> g[N];
ll ans,vis[N],fa[N];
int find(int x){return fa[x]=(x==fa[x]?x:find(fa[x]));}
void merge(int u,int v){
    u=find(u);v=find(v);
    fa[u]=v;
}   //DSU

ll kru(int s){
    queue<int> q;
    vector<int> pt;
    q.push(s);
    while(!q.empty()){
        int u=q.front();q.pop();
        if(vis[u]==1) continue;
        vis[u]=1;pt.push_back(u);
        for(auto d:g[u]){
            int v=d.v;
            if(!vis[v]) q.push(v);
        }
    }
    int mt=0;
    for(auto u:pt){
        for(auto d:g[u]){
            int v=d.v;
            et[++mt]={u,v,d.l,d.c};
        }
    }
    sort(et+1,et+mt+1);
    ll sum=0,tot=0;
    for(int i=1;i<=mt;i++){
        int u=et[i].u,v=et[i].v;
        ll c=et[i].c;
        if(find(u)==find(v)) continue;
        tot++;sum+=c;
        merge(u,v);
        if(tot==(int)pt.size()-1) break;
    }
    return sum;
}   //MST

int main(){
    //freopen("upkeep.in","r",stdin);
    //freopen("upkeep.out","w",s1tdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n>>m;
    bool mark=1;
    for(int i=1;i<=m;i++){
        cin>>e[i].u>>e[i].v>>e[i].l>>e[i].c;
        if(e[i].l!=0) mark=0;
        g[e[i].u].push_back({e[i].v,e[i].l,e[i].c});
    }
    for(int i=1;i<=n;i++) fa[i]=i;
    if(mark==1){
        for(int i=1;i<=n;i++){
            if(!vis[i]) ans+=kru(i);
        }
    }
    else{
        for(int i=1;i<=m;i++){
            ans+=e[i].c;
        }
    }
    cout<<ans;
    return 0;
}