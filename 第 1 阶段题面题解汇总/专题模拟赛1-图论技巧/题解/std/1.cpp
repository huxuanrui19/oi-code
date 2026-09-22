#include<bits/stdc++.h>
#define N 10005
#define ll long long
using namespace std;
int n,m,H,h[N];
ll dis[N][105];
vector<pair<int,int> >e[N];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>H;
    for(int i=1;i<=n;++i) cin>>h[i];
    for(int i=1;i<=m;++i){
        int u,v,w; cin>>u>>v>>w;
        e[u].push_back({v,w});
        e[v].push_back({u,w});
    }
    memset(dis,0x3f,sizeof(dis));
    priority_queue<tuple<ll,int,int> > q;
    dis[1][0]=0;
    q.push({0,1,0});
    while(!q.empty()){
        auto [d,x,y]=q.top(); q.pop();
        if(-d!=dis[x][y]) continue;
        for(auto [v,w]:e[x]){
            int ny=(h[v]>=h[x])?y+h[v]-h[x]:0;
            if(ny>H) continue;
            if(dis[x][y]+w<dis[v][ny]){
                dis[v][ny]=dis[x][y]+w;
                q.push({-dis[v][ny],v,ny});
            }
        }
    }
    for(int i=2;i<=n;++i){
        ll ans=1e18;
        for(int j=0;j<=H;++j) ans=min(ans,dis[i][j]);
        if(ans==1e18) cout<<"-1"<<" \n"[i==n];
        else cout<<ans<<" \n"[i==n];
    }
    return 0;
}