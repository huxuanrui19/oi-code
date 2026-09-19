#include<bits/stdc++.h>
#define ls(p) (p)<<1
#define rs(p) (p)<<1|1
#define cal __builtin_popcount
using namespace std;
typedef long long ll;
const int N=1e5+10,M=35;
int n,t,q;
ll tree[N<<2],tag[N<<2];
inline void push_up(int p){
    tree[p]=tree[ls(p)]|tree[rs(p)];
}
inline void add_tag(int p,int d){
    tag[p]=d;
    tree[p]=1ll<<d;
}
inline void push_down(int p){
    if(tag[p]==0) return;
    add_tag(ls(p),tag[p]);
    add_tag(rs(p),tag[p]);
    tag[p]=0;
}
void build(int p,int pl,int pr){
    if(pl==pr){
        tree[p]=1ll<<(1);
        return;
    }
    int mid=(pl+pr)>>1;
    build(ls(p),pl,mid);
    build(rs(p),mid+1,pr);
    push_up(p);
}
void update(int p,int pl,int pr,int L,int R,int d){
    if(L<=pl&&pr<=R){
        add_tag(p,d);
        return;
    }
    push_down(p);
    int mid=(pl+pr)>>1;
    if(mid>=L) update(ls(p),pl,mid,L,R,d);
    if(mid<R) update(rs(p),mid+1,pr,L,R,d);
    push_up(p);
}
ll query(int p,int pl,int pr,int L,int R){
    if(L<=pl&&pr<=R){
        return tree[p];
    }
    push_down(p);
    int mid=(pl+pr)>>1;ll ans=0;
    if(mid>=L) ans|=query(ls(p),pl,mid,L,R);
    if(mid<R) ans|=query(rs(p),mid+1,pr,L,R);
    return ans;
}
int main(){
    //freopen(".in","r",stdin);
    //freopen(".out","r",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>t>>q;
    build(1,1,n);
    for(int i=1;i<=q;i++){
        char ch;cin>>ch;
        if(ch=='C'){
            int a,b,c;cin>>a>>b>>c;
            if(a>b) swap(a,b);
            update(1,1,n,a,b,c);
        }
        else{
            int a,b;cin>>a>>b;
            if(a>b) swap(a,b);
            cout<<cal(query(1,1,n,a,b))<<"\n";
        }
    }
    return 0;
}