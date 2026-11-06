#include <bits/stdc++.h>
#define ls(p) (p)<<1
#define rs(p) (p)<<1|1
using namespace std;
typedef long long ll;
const int N=2e5+10,V=3e7+10;
const ll inf=1e18,mod=1e9+7,inv2=500000004;
ll n,v,k,q,sum;
int cnt,prod[V],pri[V];
bool vis[V];
inline ll qp(ll n,ll k){
    ll sum=1;
    while(k){
        if(k&1) sum=sum*n%mod;
        n=n*n%mod;
        k>>=1;
    }
    return sum;
}
ll tree[N<<2],tag1[N<<2],tag2[N<<2];
inline void push_up(int p){tree[p]=(tree[ls(p)]+tree[rs(p)])%mod;}
void build(int p,int pl,int pr){
    tag2[p]=1;
    if(pl==pr){
        tree[p]=0;
        return;
    }
    int mid=(pl+pr)>>1;
    build(ls(p),pl,mid);
    build(rs(p),mid+1,pr);
    push_up(p);
}
inline void addtag1(int p,int pl,int pr,ll d){
    tag1[p]=(tag1[p]+d)%mod;
    tree[p]=(tree[p]+d*(pr-pl+1))%mod;
}
inline void addtag2(int p,int pl,int pr,ll d){
    tag2[p]=(tag2[p]*d)%mod;
    tag1[p]=(tag1[p]*d)%mod;
    tree[p]=(tree[p]*d)%mod;
}
inline void push_down(int p,int pl,int pr){
    if(tag1[p]==0&&tag2[p]==1) return;
    int mid=(pl+pr)>>1;
    if(tag2[p]!=1){
        addtag2(ls(p),pl,mid,tag2[p]);
        addtag2(rs(p),mid+1,pr,tag2[p]);
        tag2[p]=1;
    }
    if(tag1[p]!=0){
        addtag1(ls(p),pl,mid,tag1[p]);
        addtag1(rs(p),mid+1,pr,tag1[p]);
        tag1[p]=0;
    }
}
void update1(int p,int pl,int pr,int L,int R,ll d){
    if(L<=pl&&pr<=R){
        addtag1(p,pl,pr,d);
        return;
    }
    push_down(p,pl,pr);
    int mid=(pl+pr)>>1;
    if(L<=mid) update1(ls(p),pl,mid,L,R,d);
    if(R>mid) update1(rs(p),mid+1,pr,L,R,d);
    push_up(p);
}
void update2(int p,int pl,int pr,int L,int R,ll d){
    if(L<=pl&&pr<=R){
        addtag2(p,pl,pr,d);
        return;
    }
    push_down(p,pl,pr);
    int mid=(pl+pr)>>1;
    if(L<=mid) update2(ls(p),pl,mid,L,R,d);
    if(R>mid) update2(rs(p),mid+1,pr,L,R,d);
    push_up(p);
}
ll query(int p,int pl,int pr,int L,int R){
    if(L<=pl&&pr<=R){
        return tree[p];
    }
    push_down(p,pl,pr);
    int mid=(pl+pr)>>1;ll ans=0;
    if(L<=mid) ans=(ans+query(ls(p),pl,mid,L,R))%mod;
    if(R>mid) ans=(ans+query(rs(p),mid+1,pr,L,R))%mod;
    return ans%mod;
}
int main(){
    freopen("prob.in","r",stdin);
    freopen("prob.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int c;cin>>c;
    cin>>n>>v>>k>>q;
    //sumk(V)
    prod[1]=1;
    for(ll i=2;i<=v;i++){
        if(!vis[i]){
            prod[i]=qp(i,k);
            vis[i]=1;pri[++cnt]=i;
        }
        for(ll j=1;j<=cnt&&pri[j]*i<=v;j++){
            ll x=pri[j]*i;
            prod[x]=(ll)prod[i]*prod[pri[j]]%mod;
            vis[x]=1;
            if(i%pri[j]==0) break;
        }
    }
    for(int i=1;i<=v;i++) sum=(sum+prod[i])%mod;
    ll invv=qp(v+1,mod-2),inv=invv*inv2%mod;
    build(1,1,n);
    for(int i=1;i<=q;i++){
        int opt,l,r;
        cin>>opt>>l>>r;
        if(l>r) swap(l,r);
        if(opt==2) cout<<query(1,1,n,l,r)<<"\n";
        else{
            update2(1,1,n,l,r,(v+1));
            update1(1,1,n,l,r,sum);
            update2(1,1,n,l,r,inv);
        }
    }
    return 0;
}