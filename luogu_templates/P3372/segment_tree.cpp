#include <iostream>
#define ls(p) ((p) << 1)
#define rs(p) (((p) << 1) | 1)
using namespace std;
typedef long long ll;
const int N = 1e6 + 10;
int n, q;
ll a[N], tree[N << 2], tag[N << 2];
void push_up(int p){
    tree[p]=tree[ls(p)]+tree[rs(p)];
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
void addtag(int p,int pl,int pr,ll c){
    tag[p]+=c;
    tree[p]+=c*(pr-pl+1);
}
void push_down(int p,int pl,int pr){
    if(tag[p]){
        int mid=(pl+pr)>>1;
        addtag(ls(p),pl,mid,tag[p]);
        addtag(rs(p),mid+1,pr,tag[p]);
        tag[p]=0;
    }
}
void update(int p,int pl,int pr,int L,int R,ll c){
    if(L<=pl&&pr<=R){
        addtag(p,pl,pr,c);
        return;
    }
    int mid=(pl+pr)>>1;
    push_down(p,pl,pr);
    if(L<=mid) update(ls(p),pl,mid,L,R,c);
    if(R>mid) update(rs(p),mid+1,pr,L,R,c);
    push_up(p);
}
ll query(int p,int pl,int pr,int L,int R){
    if(L<=pl&&pr<=R){
        return tree[p];
    }
    int mid=(pl+pr)>>1;
    push_down(p,pl,pr);
    ll sum=0;
    if(L<=mid) sum+=query(ls(p),pl,mid,L,R);
    if(R>mid) sum+=query(rs(p),mid+1,pr,L,R);
    return sum;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>a[i];
    build(1,1,n);
    while(q--){
        int op,l,r;
        cin>>op>>l>>r;
        if(op==1){
            ll num;
            cin>>num;
            update(1,1,n,l,r,num);
        }
        else{
            cout<<query(1,1,n,l,r)<<"\n";
        }
    }
    return 0;
}
