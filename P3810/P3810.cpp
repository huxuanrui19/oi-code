#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10,M=2e5+10;
const ll inf=1e18,mod=1e9+7;
int n,k,m;
struct node{
    int a,b,c,cnt,res;
    bool operator !=(const node &x) const{
        if(a!=x.a) return true;
        if(b!=x.b) return true;
        if(c!=x.c) return true;
        else return false;
    }
}e[N],et[N];
bool cmpa(node x,node y){
    if(x.a!=y.a) return x.a<y.a;
    if(x.b!=y.b) return x.b<y.b;
    return x.c<y.c;
}
bool cmpb(node x,node y){
    if(x.b!=y.b) return x.b<y.b;
    return x.c<y.c;
}

node tmp[N];
void merge(int l,int r,int mid){
    int cnt=0,i=l,j=mid+1;
    while(i<=mid&&j<=r){
        if(cmpb(et[i],et[j])) tmp[++cnt]=et[i++];
        else tmp[++cnt]=et[j++];
    }
    while(i<=mid) tmp[++cnt]=et[i++];
    while(j<=r) tmp[++cnt]=et[j++];
    for(int i=1;i<=cnt;i++) et[l+i-1]=tmp[i];
}

ll tree[M];
inline int lowbit(ll x){return x&(-x);}
void update(int pos,ll d){
    while(pos<M){
        tree[pos]+=d;
        pos+=lowbit(pos);
    }
}
ll query(int pos){
    ll ans=0;
    while(pos){
        ans+=tree[pos];
        pos-=lowbit(pos);
    }
    return ans;
}

void cdq(int l,int r){
    if(l==r) return;
    int mid=(l+r)>>1;
    cdq(l,mid);
    cdq(mid+1,r);
    int i=l,j=mid+1;
    while(j<=r){
        while(i<=mid&&et[i].b<=et[j].b){
            update(et[i].c,et[i].cnt);
            i++;
        }
        et[j].res+=query(et[j].c);
        j++;
    }
    for(int k=l;k<i;k++) update(et[k].c,-et[k].cnt);
    merge(l,r,mid);
    return;
}
ll res[N];
int main(){
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>e[i].a>>e[i].b>>e[i].c;
    sort(e+1,e+n+1,cmpa);
    for(int i=1;i<=n;i++){
        if(e[i]!=e[i-1]){
            et[++m]=e[i];
            et[m].cnt++;
        }
        else et[m].cnt++;
    }
    cdq(1,m);
    for(int i=1;i<=m;i++) res[et[i].res+et[i].cnt-1]+=et[i].cnt;
    for(int i=0;i<n;i++) cout<<res[i]<<"\n";
    return 0;
}