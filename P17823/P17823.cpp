#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
const ll inf=1e18,mod=1e9+7;
int n,ans,fa[N],siz[N],e[N];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
void merge(int u,int v){
    int ru=find(u),rv=find(v);
    if(ru==rv){
        ans-=min(e[ru],siz[ru]);
        e[ru]++;
        ans+=min(e[ru],siz[ru]);
    }
    else{
        ans-=min(e[ru],siz[ru]);
        ans-=min(e[rv],siz[rv]);
        fa[rv]=ru;
        siz[ru]+=siz[rv];
        e[ru]+=e[rv]+1;
        ans+=min(e[ru],siz[ru]);
    }
    return;
}
int main(){
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    for(int i=1;i<N;i++) fa[i]=i,siz[i]=1,e[i]=0;
    for(int i=1;i<=n;i++){
        int a,b;cin>>a>>b;
        merge(a,b);
        cout<<ans<<" ";
    }
    return 0;
}