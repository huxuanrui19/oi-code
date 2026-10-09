#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10,M=20;
const ll mod=1e9+7;
int n,k;
vector<int> g[N];
int maxn,a[N],p[N];
struct node{
    ll len,u,v;
}ans[N];
int dep[N],fa[N][M];
void dfs(int u,int f){
    fa[u][0]=f;dep[u]=dep[f]+1;
    for(int i=1;i<M;i++){
        fa[u][i]=fa[fa[u][i-1]][i-1];
    }
    for(auto d:g[u]){
        if(d==f) continue;
        dfs(d,u);
    }
}
ll lca(int u,int v){
    if(dep[u]<dep[v]) swap(u,v);
    if(u==v) return u;
    for(int j=M-1;j>=0;j--){
        if(dep[fa[u][j]]<dep[v]) continue;
        u=fa[u][j];
    }
    if(u==v) return u;
    for(int j=M-1;j>=0;j--){
        if(fa[u][j]!=fa[v][j]){
            u=fa[u][j];
            v=fa[v][j];
        }
    }
    return fa[u][0];
}
ll dist(ll u,ll v){
    return dep[u]+dep[v]-2*dep[lca(u,v)];
}
int main(){
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i]>>p[i];
    for(int i=1;i<=n;i++){
        if(p[i]==0) continue;
        g[p[i]].push_back(i);
        g[i].push_back(p[i]);
    }
    dfs(1,0);
    for(int i=1;i<=n;i++){
        if(ans[a[i]].len==0){
            if(ans[a[i]].u==0) ans[a[i]].u=i;
            else ans[a[i]].v=i,ans[a[i]].len=dist(ans[a[i]].u,i);
        }
        else{
            int u=ans[a[i]].u,v=ans[a[i]].v;
            int d1=dist(u,i),d2=dist(v,i);
            if(ans[a[i]].len<d1) ans[a[i]]={d1,u,i};
            if(ans[a[i]].len<d2) ans[a[i]]={d2,v,i};
        }
    }
    for(int i=1;i<=k;i++) cout<<ans[i].len<<"\n";
    return 0;
}