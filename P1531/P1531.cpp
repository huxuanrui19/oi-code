#include <bits/stdc++.h>
#define ls(p) (p)<<1
#define rs(p) (p)<<1|1  
using namespace std;
typedef long long ll;
const int N=2e5+10;
const ll maxn=1e18,mod=1e9+7;
int n,q,a[N],tree[N<<2];
void push_up(int p){
    tree[p]=max(tree[ls(p)],tree[rs(p)]);
}
void build(int p,int pl,int pr){
    if(pl==pr){
        tree[p]=a[pl];
        return;
    }
    int mid=(pl+pr)>>1;
    build(ls(p),pl,mid);
    build(rs(p),mid+1,pr);
    push_up(p);
}
void update(int p,int pl,int pr,int pos,int d){
    if(pl==pr){
        tree[p]=max(tree[p],d);
        return;
    }
    int mid=(pl+pr)>>1;
    if(pos<=mid) update(ls(p),pl,mid,pos,d);
    else update(rs(p),mid+1,pr,pos,d);
    push_up(p);
}
ll query(int p,int pl,int pr,int L,int R){
    if(L<=pl&&pr<=R){
        return tree[p];
    }
    int mid=(pl+pr)>>1;ll ans=0;
    if(L<=mid) ans=max(ans,query(ls(p),pl,mid,L,R));
    if(mid<R) ans=max(ans,query(rs(p),mid+1,pr,L,R));
    return ans;
}
int main(){
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>a[i];
    build(1,1,n);
    for(int i=1;i<=q;i++){
        char op;int a,b;
        cin>>op>>a>>b;
        if(op=='U') update(1,1,n,a,b);
        else cout<<query(1,1,n,a,b)<<"\n";
    }
    return 0;
}