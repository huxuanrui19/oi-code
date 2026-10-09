#include <bits/stdc++.h>
#define pii pair<int,ll>
using namespace std;
typedef long long ll;
const int N=1e6+10;
const ll maxn=1e18,mod=1e9+7;
int n,p[N],dis[N];ll sum[N],siz[N];
vector<int> g[N];
int main(){
    freopen("toptree.in","r",stdin);
    freopen("toptree.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        for(int i=2;i<=n;i++) cin>>p[i];
        for(int i=2;i<=n;i++) g[p[i]].push_back(i);
        vector<int> ord;
        ord.push_back(1);
        for(int i=0;i<n;i++){
            int u=ord[i];
            for(auto d:g[u]) ord.push_back(d);
        }
        for(int i=n-1;i>=0;i--){
            int u=ord[i];dis[u]=0;
            for(auto d:g[u]){
                dis[u]=max(dis[u],dis[d]+1);
            }
            if(g[u].size()<=2) continue;
            priority_queue<int,vector<int>,greater<int> > q;
            for(auto d:g[u]) q.push(dis[d]);
            while(q.size()>2){
                int v=q.top();q.pop();
                int w=q.top();q.pop();
                q.push(max(w+1,v+1));
            }
            q.pop();
            dis[u]=q.top()+1;
        }
        for(int i=n-1;i>=0;i--){
            int u=ord[i];siz[u]=1;
            for(auto d:g[u]){
                siz[u]+=siz[d];
                sum[u]+=sum[d]+siz[d];
            }
            if(g[u].size()<=2) continue;
            priority_queue<pii,vector<pii>,greater<pii> > q;
            for(auto d:g[u]) q.push({siz[d],sum[d]});
            while(q.size()>2){
                int v=q.top().first;ll sizv=q.top().second;q.pop();
                int w=q.top().first;ll sizw=q.top().second;q.pop();
                q.push({w+v,w+v+sizv+sizw});
            }
            sum[u]=0;
            sum[u]=q.top().first+q.top().second;q.pop();
            sum[u]+=q.top().first+q.top().second;q.pop();
        }
        cout<<dis[1]<<" "<<sum[1]<<"\n";
        for(int i=1;i<=n;i++){
            sum[i]=siz[i]=dis[i]=0;
            g[i].clear();
        }
    }
    return 0;
}