#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;
const int N=400+10,M=1e4+10;
const ld eps=1e-8;
int n,m;ld f;
struct edge{
    int u,v;ld c,t,w;
    bool operator <(const edge &x) const{
        return w<x.w;
    }
}e[M],et[M];
bool sgn(ld x){
    return (x>=eps);
}
int fa[N];
int find(int x){return (x==fa[x]?x:fa[x]=find(fa[x]));}
void merge(int u,int v){
    u=find(u);v=find(v);
    fa[u]=v;
}
bool check(ld x){
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=1;i<=m;i++){
        et[i].u=e[i].u;
        et[i].v=e[i].v;
        et[i].w=e[i].c+x*e[i].t;
    }
    sort(et+1,et+m+1);
    ll tot=0;ld ans=0;
    for(int i=1;i<=m;i++){
        int u=et[i].u,v=et[i].v;ld w=et[i].w;
        if(find(u)==find(v)) continue;
        merge(u,v);tot++;ans+=w;
        if(tot==n-1) continue;
    }
    return sgn(f-ans);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m>>f;
    for(int i=1;i<=m;i++){
        cin>>e[i].u>>e[i].v>>e[i].c>>e[i].t;
    }
    ld l=0,r=f,ans=0;
    while(sgn(r-l)){
        ld mid=(l+r)/2.0;
        if(check(mid)){
            l=mid;
            ans=mid;
        }else r=mid;
    }
    printf("%.4lf",ans);
    return 0;
}