#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3e5+10;
const ll mod=10007;
ll ls(ll x){return x<<1;}
ll rs(ll x){return x<<1|1;}
ll a[N],tree[N<<2],add[N<<2],mul[N<<2];
void push_up(int p){
	tree[p]=(tree[ls(p)]+tree[rs(p)])%mod;
}
void build(int p,int pl,int pr){
	add[p]=0;
	mul[p]=1;
	if(pl==pr){
		tree[p]=a[pl];
		return;
	}
	int mid=(pl+pr)>>1;
	build(ls(p),pl,mid);
	build(rs(p),mid+1,pr);
	push_up(p);
}
void addtag_add(int p,int pl,int pr,ll d){
	add[p]=(add[p]+d)%mod;
	tree[p]=(tree[p]+1ll*(pr-pl+1)*d%mod)%mod;
}
void addtag_mul(int p,int pl,int pr,ll d){
	add[p]=add[p]*d%mod;
	mul[p]=mul[p]*d%mod;
	tree[p]=tree[p]*d%mod;
}
void push_down(int p,int pl,int pr){
	if(add[p]==0&&mul[p]==1) return;
	int mid=(pl+pr)>>1;
	addtag_mul(ls(p),pl,mid,mul[p]);
	addtag_add(ls(p),pl,mid,add[p]);
	addtag_mul(rs(p),mid+1,pr,mul[p]);
	addtag_add(rs(p),mid+1,pr,add[p]);
	add[p]=0;
	mul[p]=1; 
}
void update_add(int L,int R,int p,int pl,int pr,ll d){
    if(L<=pl&&pr<=R){
        addtag_add(p,pl,pr,d);
        return;
    }
    push_down(p,pl,pr);
    int mid=(pl+pr)>>1;
    if(L<=mid) update_add(L,R,ls(p),pl,mid,d);
    if(R>mid) update_add(L,R,rs(p),mid+1,pr,d);
    push_up(p);
}
void update_mul(int L,int R,int p,int pl,int pr,ll d){
    if(L<=pl&&pr<=R){
        addtag_mul(p,pl,pr,d);
        return;
    }
    push_down(p,pl,pr);
    int mid=(pl+pr)>>1;
    if(L<=mid) update_mul(L,R,ls(p),pl,mid,d);
    if(R>mid) update_mul(L,R,rs(p),mid+1,pr,d);
    push_up(p);
}
ll query(int L,int R,int p,int pl,int pr){
    if(L<=pl&&pr<=R){
        return tree[p];
    }
    push_down(p,pl,pr);
    ll res=0;
    int mid=(pl+pr)>>1;
    if(L<=mid) res=(res+query(L,R,ls(p),pl,mid))%mod;
    if(R>mid) res=(res+query(L,R,rs(p),mid+1,pr))%mod;
    return res;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    build(1,1,n);
    for(int i=1;i<=n;i++){
        int opt,l,r,val;
        cin>>opt>>l>>r>>val;
        if(opt==0){
            update_add(l,r,1,1,n,val);
        }
        else if(opt==1) update_mul(l,r,1,1,n,val);
        else cout<<(query(r,r,1,1,n)+mod)%mod<<"\n";
    }
	return 0;
}

