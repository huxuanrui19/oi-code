#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1.5e4+10,M=1e6+10;
const ll inf=1e18,mod=1e9+7;
int n,m,k;
struct edge{
    int u,v;ll w;
    bool operator <(const edge &x) const{
        return w<x.w;
    }
}e[M],et[M];
ll a[15];

int fa[N];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
void merge(int u,int v){
    u=find(u),v=find(v);
    fa[u]=v;
}


ll ans=0,cnt=0;
int main(){
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++) cin>>e[i].u>>e[i].v>>e[i].w;
    sort(e+1,e+m+1);
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=1;i<=m;i++){
        int u=e[i].u,v=e[i].v;ll w=e[i].w;
        if(find(u)==find(v)) continue;
        merge(u,v);
        et[++cnt]={u,v,w};
        ans+=w;
        if(cnt==n-1) break;
    }
    for(int i=1;i<=k;i++){
        cin>>a[i];
        for(int j=1;j<=n;j++){
            ll w;cin>>w;
            et[++cnt]={i+n,j,w};
        }
    }
    sort(et+1,et+cnt+1);
    for(int i=1;i<(1<<k);i++){
        ll cur=0,tot=0;
        for(int j=1;j<=n+k;j++) fa[j]=j;
        int num=n;
        for(int j=1;j<=k;j++) num+=((i>>(j-1))&1),cur+=((i>>(j-1))&1)*a[j];
        for(int j=1;j<=cnt;j++){
            int u=et[j].u,v=et[j].v;ll w=et[j].w;
            if(u>n){
                int uu=u-n;
                if(!((i>>(uu-1))&1)) continue; 
            }
            if(find(u)==find(v)) continue;
            merge(u,v);tot++;cur+=w;
            if(tot==num-1) break;
        }
        ans=min(ans,cur);
    }
    cout<<ans;
    return 0;
}