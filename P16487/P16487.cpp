#include<bits/stdc++.h>
#define pii pair<ll,pair<int,int> >
using namespace std;
typedef long long ll;
const int N=100+10,M=1000+10;
const ll maxn=1e18,mod=1e9+7;
int n,m,sn[N],w[N],ti[N][M],s[N][M];
vector<pii> g[N][M];
ll dis[N][M][2],vis[N][M][2];
struct sta{
    ll w;
    ll type,x,y;
    bool operator >(const sta &t) const{
        return w>t.w;
    }
};
void dijk(int x,int y){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sn[i];j++) dis[i][j][1]=dis[i][j][0]=maxn,vis[i][j][0]=vis[i][j][1]=0;
    }
    dis[x][y][1]=0;
    priority_queue<sta,vector<sta>,greater<sta> > q;
    q.push({0,1,x,y});
    while(!q.empty()){
        int u=q.top().x,v=q.top().y,type=q.top().type;q.pop();
        if(vis[u][v][type]) continue;
        vis[u][v][type]=1;
        for(auto d:g[u][v]){
            ll ww=d.first,a=d.second.first,b=d.second.second;
            ll nd=0,nt=-1;
            if(a==u){
                if(type==1) nd=dis[u][v][type]+ww+w[u],nt=0;
                else nd=dis[u][v][type]+ww,nt=0;
            }
            else{
                nd=dis[u][v][type]+ww;nt=1;
            }
            if(dis[a][b][nt]>nd){
                dis[a][b][nt]=nd;
                q.push({nd,nt,a,b});
            }
        }
    }
    return;
}
int main(){
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll t,idx=0;cin>>t;
    while(t--){
        cin>>n;idx++;
        for(int i=1;i<=n;i++){
            cin>>sn[i]>>w[i];
            for(int j=1;j<sn[i];j++){
                cin>>ti[i][j];
                g[i][j].push_back({ti[i][j],{i,j+1}});
                g[i][j+1].push_back({ti[i][j],{i,j}});
            }
        }
        cin>>m;
        for(int i=1;i<=m;i++){
            int x1,y1,x2,y2,ww;
            cin>>x1>>y1>>x2>>y2>>ww;
            g[x1][y1].push_back({ww,{x2,y2}});
            g[x2][y2].push_back({ww,{x1,y1}});
        }
        int q;cin>>q;
        cout<<"Case #"<<idx<<":\n";
        while(q--){
            int x1,y1,x2,y2;cin>>x1>>y1>>x2>>y2;
            dijk(x1,y1);
            cout<<" ";
            ll ans=min(dis[x2][y2][0],dis[x2][y2][1]);
            if(ans==maxn) cout<<"-1\n";
            else cout<<ans<<"\n";
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sn[i];j++) g[i][j].clear();
        }
    }
    return 0;
}