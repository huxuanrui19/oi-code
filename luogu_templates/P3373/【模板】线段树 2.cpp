#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ls(p) (p)<<1
#define rs(p) (p)<<1|1
const int N=1e5+10;
ll a[N],tree[N<<2],add[N<<2],mul[N<<2],mod;
void push_up(ll p){
    tree[p]=(tree[ls(p)]+tree[rs(p)])%mod;
}
void build(ll p,ll pl,ll pr){
    add[p]=0;
    mul[p]=1;
    if(pl==pr){tree[p]=a[pl]%mod;return;}
    ll mid=(pl+pr)>>1;
    build(ls(p),pl,mid);
    build(rs(p),mid+1,pr);
    push_up(p);
}
void push_down(ll p,ll pl,ll pr){
    if(add[p]==0&&mul[p]==1) return;
    ll mid=(pl+pr)>>1;
    tree[ls(p)]=(tree[ls(p)]*mul[p]%mod+add[p]*(mid-pl+1)%mod)%mod;
    mul[ls(p)]=mul[ls(p)]*mul[p]%mod;
    add[ls(p)]=(add[ls(p)]*mul[p]%mod+add[p])%mod;
    tree[rs(p)]=(tree[rs(p)]*mul[p]%mod+add[p]*(pr-mid)%mod)%mod;
    mul[rs(p)]=mul[rs(p)]*mul[p]%mod;
    add[rs(p)]=(add[rs(p)]*mul[p]%mod+add[p])%mod;
    add[p]=0;
    mul[p]=1;
}
void update_add(ll L,ll R,ll p,ll pl,ll pr,ll d){
    if(L<=pl&&pr<=R){
        add[p]=(add[p]+d)%mod;
        tree[p]=(tree[p]+d*(pr-pl+1)%mod)%mod;
        return;
    }
    push_down(p,pl,pr);
    ll mid=(pl+pr)>>1;
    if(L<=mid) update_add(L,R,ls(p),pl,mid,d);
    if(R>mid) update_add(L,R,rs(p),mid+1,pr,d);
    push_up(p);
}
void update_mul(ll L,ll R,ll p,ll pl,ll pr,ll d){
    if(L<=pl&&pr<=R){
        mul[p]=mul[p]*d%mod;
        add[p]=add[p]*d%mod;
        tree[p]=tree[p]*d%mod;
        return;
    }
    push_down(p,pl,pr);
    ll mid=(pl+pr)>>1;
    if(L<=mid) update_mul(L,R,ls(p),pl,mid,d);
    if(R>mid) update_mul(L,R,rs(p),mid+1,pr,d);
    push_up(p);
}
ll query(ll L,ll R,ll p,ll pl,ll pr){
    if(L<=pl&&pr<=R) return tree[p]%mod;
    push_down(p,pl,pr);
    ll res=0,mid=(pl+pr)>>1;
    if(L<=mid) res=(res+query(L,R,ls(p),pl,mid))%mod;
    if(R>mid) res=(res+query(L,R,rs(p),mid+1,pr))%mod;
    return res;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin>>n>>m>>mod;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    build(1,1,n);
    for(int i=1;i<=m;i++){
        ll op,x,y;
        cin>>op>>x>>y;
        if(op==1){
            ll k;
            cin>>k;
            update_mul(x,y,1,1,n,k);
        }
        else if(op==2){
            ll k;
            cin>>k;
            update_add(x,y,1,1,n,k);
        }
        else{
            cout<<query(x,y,1,1,n)<<'\n';
        }
    }
    return 0;
}
