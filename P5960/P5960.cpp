#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e3+10;
const ll inf=1e18,mod=1e9+7;
int n,m;
vector<pair<ll,int> > g[N];
inline void addedge(int u,int v,int w){g[u].push_back({w,v});}
ll d[N],inq[N],cnt[N];
void spfa(int s){
    queue<int> q;q.push(s);
    for(int i=0;i<=n;i++) d[i]=inf;
    d[s]=0;
    while(!q.empty()){
        int u=q.front();q.pop();inq[u]=0;
        for(auto x:g[u]){
            int v=x.second;ll w=x.first;
            if(d[v]>d[u]+w){
                d[v]=d[u]+w;
                cnt[v]++;
                if(cnt[v]>=n+1){
                    cout<<"NO";
                    return;
                }
                if(!inq[v]){
                    q.push(v);
                    inq[v]=1;
                }
            }
        }
    }
    for(int i=1;i<=n;i++) cout<<d[i]<<" ";
}
int main(){
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v,w;cin>>u>>v>>w;
        addedge(v,u,w);
    }
    for(int i=1;i<=n;i++) addedge(0,i,0);
    spfa(0);
    return 0;
}