#include <bits/stdc++.h>
#define ls(p) (p)<<1
#define rs(p) (p)<<1|1
using namespace std;
typedef long long ll;
const int N=2e5+10;
const ll maxn=1e18,mod=1e9+7;
vector<int> g[N];
ll n,q;
ll ans,a[N];
void dfs(int u,int fa,int tar,int sum){
    sum+=a[u];
    if(u==tar){
        ans=sum;return;
    }
    for(auto d:g[u]){
        if(d!=fa) dfs(d,u,tar,sum);
    }
}

ll tag1[N<<2],tree1[N<<2];
void push_up(int p){
    tree1[p]=tree1[ls(p)]+tree1[rs(p)];
}
void build(int p,int pl,int pr){
    if(pl==pr){
        tree1[p]=a[pl];
        return;
    }
    int mid=(pl+pr)>>1;
    build(ls(p),pl,mid);
    build(rs(p),mid+1,pr);
    push_up(p);
}
void add_tag(int p,ll pl,ll pr,ll d){
    tag1[p]+=d;
    tree1[p]+=(pr-pl+1)*d;
}
void push_down(int p,int pl,int pr){
    if(!tag1[p]) return;
    int mid=(pl+pr)>>1;
    add_tag(ls(p),pl,mid,tag1[p]);
    add_tag(rs(p),mid+1,pr,tag1[p]);
    tag1[p]=0;
}
void update(int p,int pl,int pr,int L,int R,ll d){
    if(L<=pl&&pr<=R){
        add_tag(p,pl,pr,d);
        return;
    }
    push_down(p,pl,pr);
    int mid=(pl+pr)>>1;
    if(L<=mid) update(ls(p),pl,mid,L,R,d);
    if(R>mid) update(rs(p),mid+1,pr,L,R,d);
    push_up(p);
}
ll query(int p,int pl,int pr,int pos){
    if(pl==pr){
        return tree1[p];
    }
    push_down(p,pl,pr);
    int mid=(pl+pr)>>1;
    if(mid>=pos) return query(ls(p),pl,mid,pos);
    else return query(rs(p),mid+1,pr,pos);
}
ll query2(ll p,ll pl,ll pr,ll L,ll R){
    if(L<=pl&&pr<=R){
        return tree1[p];
    }
    push_down(p,pl,pr);
    int mid=(pl+pr)>>1;ll ans=0;
    if(L<=mid) ans+=query2(ls(p),pl,mid,L,R);
    if(mid<R) ans+=query2(rs(p),mid+1,pr,L,R);
    return ans;
}
int main(){
    freopen("thousand.in","r",stdin);
    freopen("thousand.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n>>q;
    for(int i=1;i<n;i++){
        int p;cin>>p;
        g[p].push_back(i+1);
        g[i+1].push_back(p);
    }
    if(n<=5000+100){
        ll xs=0;
        for(int i=1;i<=q;i++){
            int op;cin>>op;
            if(op==1){
                ll l,r,x;cin>>l>>r>>x;
                l=(l^xs)%n+1;
                r=(r^xs)%n+1;
                x=(x^xs)%n+1;
                for(int j=l;j<=r;j++) a[j]+=x;
            }
            else if(op==2){
                ll u,v;cin>>u>>v;
                u=(u^xs)%n+1;
                v=(v^xs)%n+1;
                ans=0;
                dfs(u,0,v,0);
                cout<<ans<<"\n";
                xs^=ans;
            }
        }
    }
    else if((int)g[1].size()==n-1){
        build(1,1,n);ll xs=0;
        for(int i=1;i<=q;i++){
            int opt;cin>>opt;
            if(opt==1){
                ll l,r;ll x;
                cin>>l>>r>>x;
                l=(l^xs)%n+1;
                r=(r^xs)%n+1;
                x=(x^xs)%n+1;
                update(1,1,n,l,r,x);
            }
            else if(opt==2){
                ll u,v;cin>>u>>v;
                u=(u^xs)%n+1;
                v=(v^xs)%n+1;ans=0;
                ans=query(1,1,n,u);
                if(u!=v) ans+=query(1,1,n,v);
                if(u!=1&&v!=1&&u!=v) ans+=query(1,1,n,1);
                cout<<ans<<"\n";
                xs^=ans;
            }
        }
    }
    else{
        build(1,1,n);ll xs=0;
        for(int i=1;i<=q;i++){
            int opt;cin>>opt;
            if(opt==1){
                ll l,r;ll x;
                cin>>l>>r>>x;
                l=(l^xs)%n+1;
                r=(r^xs)%n+1;
                x=(x^xs)%n+1;
                update(1,1,n,l,r,x);
            }
            else if(opt==2){
                ll u,v;cin>>u>>v;
                u=(u^xs)%n+1;
                v=(v^xs)%n+1;ans=0;
                if(u>v) swap(u,v);
                ans=query2(1,1,n,u,v);
                cout<<ans<<"\n";
                xs^=ans;
            }
        }
    }
    return 0;
}