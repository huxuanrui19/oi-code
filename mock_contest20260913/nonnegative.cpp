#include <bits/stdc++.h>
#define ls(p) (p)<<1
#define rs(p) (p)<<1|1
#define pii pair<ll,ll>
#define num first
#define pos second
using namespace std;
typedef long long ll;
const int N=1e5+10;
const ll inf=1e18,mod=1e9+7;
ll n;
struct node{
    ll x,idx;
    bool operator <(const node &tmp)const{
        if(x!=tmp.x) return x<tmp.x;
        else return idx<tmp.idx;
    }
}a[N];
pii tree[N<<2];
inline pii get_min(pii x,pii y){
    if(x.num<y.num) return x;
    else return y;
}
inline void push_up(int p){
    tree[p]=get_min(tree[ls(p)],tree[rs(p)]);
}
void build(int p,int pl,int pr){
    if(pl==pr){
        tree[p]={a[pl].idx,pl};
        return;
    }
    int mid=(pl+pr)>>1;
    build(ls(p),pl,mid);
    build(rs(p),mid+1,pr);
    push_up(p);
}
pii query(int p,int pl,int pr,int L,int R){
    if(L<=pl&&pr<=R){
        return tree[p];
    }
    pii ans={inf,-1};int mid=(pl+pr)>>1;
    if(mid>=L) ans=get_min(ans,query(ls(p),pl,mid,L,R));
    if(mid<R) ans=get_min(ans,query(rs(p),mid+1,pr,L,R));
    return ans;
}
void del(int p,int pl,int pr,int pos){
    if(pl==pr){
        tree[p]={inf,pl};
        return;
    }
    int mid=(pl+pr)>>1;
    if(mid>=pos) del(ls(p),pl,mid,pos);
    else del(rs(p),mid+1,pr,pos);
    push_up(p);
}
int main(){
    freopen("nonnegative.in","r",stdin);
    freopen("nonnegative.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n;for(int i=1;i<=n;i++) cin>>a[i].x;
    for(int i=1;i<=n;i++) a[i].idx=i;
    sort(a+1,a+n+1);
    ll sum=0;
    for(int i=1;i<=n;i++) sum+=a[i].x;
    if(sum<0){
        cout<<"-1";return 0;
    }
    sum=0;build(1,1,n);
    for(int i=1;i<=n;i++){
        int pos=lower_bound(a+1,a+n+1,(node){-sum,-inf})-a;
        pii cnt=query(1,1,n,pos,n);
        cout<<cnt.num<<" ";
        sum+=a[cnt.pos].x;del(1,1,n,cnt.pos);
    }
    return 0;
}