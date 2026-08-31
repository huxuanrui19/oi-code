#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e4+10;
ll n,m,a[N];
vector<int> g[N];
int tot,dfn[N],low[N];
int top,stk[N],instk[N];
int siz,scc_siz[N],sccno[N];
void tarjan(int u){
    dfn[u]=low[u]=++tot;
    stk[++top]=u;instk[u]=1;
    
    for(auto v:g[u]){
        if(!dfn[v]){
            tarjan(v);
            low[u]=min(low[v],low[u]);
        }
        else if(instk[v]) low[u]=min(low[u],dfn[v]);
    }

    if(dfn[u]==low[u]){
        siz++;ll x=0;
        do{
            x=stk[top--];instk[x]=0;
            scc_siz[siz]++;sccno[x]=siz;
        }while(x!=u);
    }
}
vector<int> gt[N];
ll scc_a[N];
void build(){
    for(int i=1;i<=n;i++){
        for(auto d:g[i]){
            if(sccno[i]==sccno[d]) continue;
            gt[sccno[i]].push_back(sccno[d]);
        }
    }
    for(int i=1;i<=n;i++) scc_a[sccno[i]]+=a[i];
    return;
}
ll dp[N],deg[N];
queue<int> q;
void topo(){
    for(int i=1;i<=siz;i++){
        for(auto d:gt[i]){
            deg[d]++;
        }
    }
    for(int i=1;i<=siz;i++){
        if(deg[i]==0) q.push(i),dp[i]=scc_a[i];
    }
    while(!q.empty()){
        ll u=q.front();q.pop();
        for(auto d:gt[u]){
            dp[d]=max(dp[d],dp[u]+scc_a[d]);
            deg[d]--;
            if(!deg[d]) q.push(d);
        }
    }
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1,u,v;i<=m;i++){
        cin>>u>>v;
        g[u].push_back(v);
    }
    for(int i=1;i<=n;i++){
        if(!dfn[i]) tarjan(i);
    }
    build();
    topo();
    ll ans=0;
    for(int i=1;i<=siz;i++) ans=max(ans,dp[i]);
    cout<<ans;
    return 0;
}