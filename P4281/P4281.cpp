#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10,M=25;
const ll maxn=1e18,mod=1e9+7;
int n,m;
vector<int> g[N];
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
struct node{
    int d,u,sona,sonb;
    bool operator <(const node &x){
        return d>x.d;
    }
};
pair<int,ll> cal(int a,int b,int c){
    vector<node> s;s.resize(3);
    int u=lca(a,b),v=lca(a,c),w=lca(b,c);
    s[0]={dep[u],u,a,b};
    s[1]={dep[v],v,a,c};
    s[2]={dep[w],w,b,c};
    sort(s.begin(),s.end());
    int t=a^b^c^s[0].sona^s[0].sonb;
    return {s[0].u,dep[s[0].sona]+dep[s[0].sonb]-2*s[0].d+s[0].d+dep[t]-2*s[1].d};
}
int main(){
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n>>m;
    for(int i=1;i<n;i++){
        int u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,1);
    for(int i=1;i<=m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        auto d=cal(a,b,c);
        cout<<d.first<<" "<<d.second<<"\n";
    }
    return 0;
}