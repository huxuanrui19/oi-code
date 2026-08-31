#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e4+10;
int n,m;
vector<int> g[N];
int tot,dfn[N],low[N];
int iscut[N];
void tarjan(int u,int root){
    low[u]=dfn[u]=++tot;
    ll ch=0;
    for(auto v:g[u]){
        if(!dfn[v]){
            tarjan(v,root);
            low[u]=min(low[v],low[u]);
            if(low[v]>=dfn[u]){
                ch++;
                if(ch>1||u!=root) iscut[u]=1;
            }
        }
        else low[u]=min(dfn[v],low[u]);
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1,u,v;i<=m;i++){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        if(!dfn[i]) tarjan(i,i);
    }
    ll sum=0;
    for(int i=1;i<=n;i++) sum+=iscut[i];
    cout<<sum<<"\n";
    for(int i=1;i<=n;i++){
        if(iscut[i]) cout<<i<<" ";
    }
    return 0;
}