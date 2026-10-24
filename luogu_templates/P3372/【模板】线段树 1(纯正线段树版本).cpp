#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ls(p) (p)<<1
#define rs(p) (p)<<1|1
const int N=1e5+10;
ll a[N],tree[N<<2],tag[N<<2];
void push_up(ll p){
	tree[p]=tree[ls(p)]+tree[rs(p)];
}
void build(ll p,ll pl,ll pr){
	tag[p]=0;
	if(pl==pr){tree[p]=a[pl];return;}
	ll mid=(pl+pr)>>1;
	build(ls(p),pl,mid);
	build(rs(p),mid+1,pr);
	push_up(p);
}
void addtag(ll p,ll pl,ll pr,ll d){
	tag[p]+=d;
	tree[p]+=d*(pr-pl+1);
}
void push_down(ll p,ll pl,ll pr){
	if(tag[p]){
		ll mid=(pl+pr)>>1;
		addtag(ls(p),pl,mid,tag[p]);
		addtag(rs(p),mid+1,pr,tag[p]);
		tag[p]=0;
	}
}
void update(ll L,ll R,ll p,ll pl,ll pr,ll d){
	if(L<=pl&&pr<=R){
		addtag(p,pl,pr,d);
		return;
	}
	push_down(p,pl,pr);
	ll mid=(pl+pr)>>1;
	if(L<=mid) update(L,R,ls(p),pl,mid,d);
	if(R>mid) update(L,R,rs(p),mid+1,pr,d);
	push_up(p);
}
ll query(ll L,ll R,ll p,ll pl,ll pr){
	if(pl>=L&&R>=pr) return tree[p];
	push_down(p,pl,pr);
	ll res=0,mid=(pl+pr)>>1;
	if(L<=mid) res+=query(L,R,ls(p),pl,mid);
	if(R>mid) res+=query(L,R,rs(p),mid+1,pr);
	return res;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,m;
	cin>>n>>m;
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
			update(x,y,1,1,n,k);
		}
		else{
			cout<<query(x,y,1,1,n)<<'\n';
		}
	}
	return 0;
}

