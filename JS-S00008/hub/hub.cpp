#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10;
vector<int> g[N];
int n,k,f[20][N],flag[N],dep[N],col[N];
void dfs(int u,int fa){
    f[0][u]=fa;dep[u]=dep[fa]+1;
    for(int i=1;i<20;i++) f[i][u]=f[i-1][f[i-1][u]];
    for(auto d:g[u]){
        if(d!=fa) dfs(d,u);
    }
}
int lca(int u,int v){
    if(u==v) return u;
    if(dep[u]<dep[v]) swap(u,v);
    for(int i=19;i>=0;i--){
        if(dep[f[i][u]]<dep[v]) continue;
        u=f[i][u];
    }
    if(u==v) return u;
    for(int i=19;i>=0;i--){
        if(f[i][u]==f[i][v]) continue;
        u=f[i][u];v=f[i][v];
    }
    return f[0][u];
}
inline int dist(int u,int v){
    return dep[u]+dep[v]-2*dep[lca(u,v)];
}
void dfs2(int u,int fa,int c){
    col[u]=c;
    for(auto d:g[u]){
        if(d==fa||col[d]||flag[d]==0) continue;
        dfs2(d,u,c);
    }
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int c,t;cin>>c>>t;
    while(t--){
        cin>>n>>k;
        for(int i=1;i<n;i++){
            int u,v;cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        if(n<=20){
            dfs(1,1);
            int ans=1e9;
            for(int i=0;i<(1<<n);i++){
                int cnt=0;
                for(int j=0;j<n;j++){
                    col[j+1]=0;
                    if((1<<j)&i){
                        flag[j+1]=1;
                        cnt++;
                    }else flag[j+1]=0;
                }
                if(cnt!=k) continue;
                int cur=0;
                for(int j=1;j<=n;j++){
                    if(!flag[j]) continue;
                    else if(!col[j]){
                        ++cur;
                        dfs2(j,j,cur);
                    }
                }
                if(cur!=2) continue;
                int maxn=0;
                for(int j=1;j<=n;j++){
                    if(flag[j]) continue;
                    int minn=1e9;
                    for(int k=1;k<=n;k++){
                        if(flag[k]==0) continue;
                        minn=min(minn,dist(j,k));
                    }
                    maxn=max(maxn,minn);
                }
                ans=min(ans,maxn);
            }
            cout<<ans<<"\n";
        }
        else cout<<"1\n";
        for(int i=1;i<=n;i++) g[i].clear();
    }
    return 0;
}
