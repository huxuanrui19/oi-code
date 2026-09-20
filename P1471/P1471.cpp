#include<bits/stdc++.h>
#define ls(p) (p)<<1
#define rs(p) (p)<<1|1
using namespace std;
typedef double ld;
const int N=1e5+10;
int n,m;
ld a[N],tree1[N<<2],tree2[N<<2],tag[N<<2];
inline void push_up(int p){
    tree1[p]=tree1[ls(p)]+tree1[rs(p)];
    tree2[p]=tree2[ls(p)]+tree2[rs(p)];
}
inline void add_tag(int p,int pl,int pr,ld d){
    tree2[p]+=(pr-pl+1)*d*d+2*d*tree1[p];
    tree1[p]+=(pr-pl+1)*d;
    tag[p]+=d;
}
inline void push_down(int p,int pl,int pr){
    if(tag[p]==0) return;
    int mid=(pl+pr)>>1;
    add_tag(ls(p),pl,mid,tag[p]);
    add_tag(rs(p),mid+1,pr,tag[p]);
    tag[p]=0;
}
inline void build(int p,int pl,int pr){
    if(pl==pr){
        tree1[p]=a[pl];
        tree2[p]=a[pl]*a[pl];
        return;
    }
    int mid=(pl+pr)>>1;
    build(ls(p),pl,mid);
    build(rs(p),mid+1,pr);
    push_up(p);
}
inline void update(int p,int pl,int pr,int L,int R,ld k){
    if(L<=pl&&pr<=R){
        add_tag(p,pl,pr,k);
        return;
    }
    push_down(p,pl,pr);
    int mid=(pl+pr)>>1;
    if(L<=mid) update(ls(p),pl,mid,L,R,k);
    if(mid<R) update(rs(p),mid+1,pr,L,R,k);
    push_up(p);
}
inline ld query1(int p,int pl,int pr,int L,int R){
    if(L<=pl&&pr<=R) return tree1[p];
    push_down(p,pl,pr);
    int mid=(pl+pr)>>1;
    ld ans=0;
    if(L<=mid) ans+=query1(ls(p),pl,mid,L,R);
    if(R>mid) ans+=query1(rs(p),mid+1,pr,L,R);
    return ans;
}
inline ld query2(int p,int pl,int pr,int L,int R){
    if(L<=pl&&pr<=R) return tree2[p];
    push_down(p,pl,pr);
    int mid=(pl+pr)>>1;
    ld ans=0;
    if(L<=mid) ans+=query2(ls(p),pl,mid,L,R);
    if(R>mid) ans+=query2(rs(p),mid+1,pr,L,R);
    return ans;
}
inline ld get_ave(int L,int R){
    return query1(1,1,n,L,R)/(R-L+1);
}
inline ld get_var(int L,int R){
    ld ave=get_ave(L,R);
    ld sum=ave*ave*(R-L+1)+query2(1,1,n,L,R)-2*query1(1,1,n,L,R)*ave;
    return sum/(R-L+1);
}
int main(){
    //freopen(".in","r",stdin);
    //freopen(".out","r",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    build(1,1,n);
    while(m--){
        int op;cin>>op;
        if(op==1){
            int x,y;ld k;cin>>x>>y>>k;
            update(1,1,n,x,y,k);
        }
        else if(op==2){
            int x,y;cin>>x>>y;
            printf("%.4lf\n",get_ave(x,y));
        }
        else{
            int x,y;cin>>x>>y;
            printf("%.4lf\n",get_var(x,y));
        }
    }
    return 0;
}