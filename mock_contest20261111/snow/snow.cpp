#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
const ll inf=1e18,mod=1e9+7;
vector<pair<int,int> > g[N];
int dfs(int u,int fa){
    if(u!=fa&&g[u].size()==1) return 1;
    ll ans=0;
    for(auto d:g[u]){
        int v=d.first;
        if(v==fa) continue;
        ans+=dfs(v,u);
    }
    return ans;
}
int main(){
    freopen("snow.in","r",stdin);
    freopen("snow.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int q;cin>>q;
    while(q--){
        int n;cin>>n;
        int lst=-1,flag1=1,flag2=1;
        for(int i=1;i<n;i++){
            int u,v,w;cin>>u>>v>>w;
            g[u].push_back({v,w});
            g[v].push_back({u,w});
            if(lst!=w&&lst!=-1) flag1=0;
            if(w!=0) flag2=0;
            lst=w;
        }
        if(flag2) cout<<"0\n";
        else if(flag1){
            for(int i=1;i<=n;i++){
                if(g[i].size()==1){
                    cout<<dfs(i,i)<<"\n";
                    goto out;
                }
            }
            out: ;
        }
        else cout<<(n-1)<<"\n";
        for(int i=1;i<=n;i++) g[i].clear();
    }
    return 0;
}