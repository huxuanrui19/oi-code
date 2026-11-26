#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3e5+10;
const ll inf=1e18,mod=1e9+7;
int n,m,fa[N],siz[N];
struct op{
    int fx,fy,sizx,sizy;
};
stack<op> his;
int find(int x){return x==fa[x]?x:find(fa[x]);}
void merge(int x,int y){
    int rtx=find(x),rty=find(y);
    if(rtx==rty){
        his.push({-1,-1,-1,-1});
        return;
    }
    if(siz[rtx]>siz[rty]) swap(rtx,rty);
    his.push({rtx,rty,siz[rtx],siz[rty]});
    fa[rtx]=rty;
    siz[rty]+=siz[rtx];
}
void undo(){
    if(his.empty()) return;
    auto o=his.top();his.pop();
    if(o.fx==-1) return;
    int rtx=o.fx,rty=o.fy;
    fa[rtx]=rtx;
    fa[rty]=rty;
    siz[rtx]=o.sizx;siz[rty]=o.sizy;
}
int main(){
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n>>m;
    for(int i=1;i<=n;i++) fa[i]=i,siz[i]=1;
    for(int i=1;i<=m;i++){
        int opt;cin>>opt;
        if(opt==1){
            int u,v;cin>>u>>v;
            merge(u,v);
        }
        else if(opt==2){
            undo();
        }
        else if(opt==3){
            int u,v;cin>>u>>v;
            if(find(u)==find(v)) cout<<"Yes\n";
            else cout<<"No\n";
        }
    }
    return 0;
}