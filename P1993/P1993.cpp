#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e3+10;
const ll inf=1e18,mod=1e9+7;
int n,m;
vector<pair<ll,int> >g[N];
inline void addedge(int u,int v,ll w){
    g[u].push_back({w,v});
}
ll d[N],inq[N],cnt[N];
void spfa(int s){
    deque<int> q;q.push_back(s);inq[s]=1;
    for(int i=0;i<=n;i++) d[i]=inf;
    d[s]=0;
    while(!q.empty()){
        int u=q.front();q.pop_front();inq[u]=0;
        for(auto x:g[u]){
            int v=x.second;ll w=x.first;
            if(d[v]>d[u]+w){
                d[v]=d[u]+w;
                cnt[v]++;
                if(cnt[v]>=n+1){
                    cout<<"No";
                    return;
                }
                if(!inq[v]){
                    if(!q.empty()&&d[v]<d[q.front()]) q.push_front(v);
                    else q.push_back(v);
                    inq[v]=1;
                }
            }
        }
    }
    cout<<"Yes";
}
int main(){
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int opt,a,b;ll c;cin>>opt>>a>>b;
        if(opt==1){
            cin>>c;
            addedge(a,b,-c);
        }else if(opt==2){
            cin>>c;
            addedge(b,a,c);
        }else{
            addedge(a,b,0);
            addedge(b,a,0);
        }
    }
    for(int i=1;i<=n;i++) addedge(0,i,0);
    spfa(0);
    return 0;
}