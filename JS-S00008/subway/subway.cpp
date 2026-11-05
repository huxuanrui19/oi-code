#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e2+10,M=5e5+10,D=25;
const ll inf=1e18;
ll n,m,d,q,w[M],k[N],g[N][N];
int siz[M],to[D][M];ll val[D][M];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int c;cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            int u,t;
            cin>>u>>t;
            siz[u]++;
            val[siz[u]][u]=t;
            to[siz[u]][u]=i;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) g[i][j]=inf;
        g[i][i]=0;
    }
    for(int u=1;u<=m;u++){
        for(int i=1;i<=siz[u];i++){
            for(int j=i+1;j<=siz[u];j++){
                int x=to[i][u],y=to[j][u];
                g[x][y]=min(g[x][y],val[i][u]+val[j][u]);
                g[y][x]=min(g[y][x],val[i][u]+val[j][u]);
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
            }
        }
    }
    while(q--){
        int x,y;cin>>x>>y;
        ll ans=inf;
        for(int i=1;i<=siz[x];i++){
            for(int j=1;j<=siz[y];j++){
                int u=to[i][x],v=to[j][y];
                ans=min(ans,w[x]+w[y]+val[i][x]+val[j][y]+g[u][v]);
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
