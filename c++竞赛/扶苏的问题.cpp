#include<bits/stdc++.h>
#define ls(p) (p)<<1
#define rs(p) (p)<<1|1
using namespace std;
template < typename T >
void read(T &x){
	int f;
	x=0,f=1;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f*=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=(x<<3)+(x<<1)+(ch&15);
		ch=getchar();
	}
	x*=f;
}
typedef long long ll;
const int N=1e6+10;
const ll inf=-1e18-10;
ll n,q,a[N],tree[N<<2],tag1[N<<2],tag2[N<<2];	//tag1:add;tag2:change;
void push_up(int p){
	tree[p]=max(tree[ls(p)],tree[rs(p)]);
}
void build(int p,int pl,int pr){
	if(pl==pr){
		tree[p]=a[pl];
		tag1[p]=0;tag2[p]=inf;
		return;
	}
	tag1[p]=0;tag2[p]=inf;
	int mid=(pl+pr)>>1;
	build(ls(p),pl,mid);
	build(rs(p),mid+1,pr);
	push_up(p);
}
void addtag1(int p,int pl,int pr,ll c){
	tag1[p]+=c;tree[p]+=c;
}
void addtag2(int p,int pl,int pr,ll c){
	tag1[p]=0;tag2[p]=c;tree[p]=c;
}
void push_down(int p,int pl,int pr){
	int mid=(pl+pr)>>1;
	if(tag2[p]!=inf){
		addtag2(ls(p),pl,mid,tag2[p]);
		addtag2(rs(p),mid+1,pr,tag2[p]);
		tag2[p]=inf;
	}
	if(tag1[p]!=0){
		addtag1(ls(p),pl,mid,tag1[p]);
		addtag1(rs(p),mid+1,pr,tag1[p]);
		tag1[p]=0;
	}
}
void update1(int p,int pl,int pr,int L,int R,ll c){
	if(L<=pl&&pr<=R){
		addtag1(p,pl,pr,c);
		return;
	}
	int mid=(pl+pr)>>1;
	push_down(p,pl,pr);
	if(L<=mid) update1(ls(p),pl,mid,L,R,c);
	if(R>mid) update1(rs(p),mid+1,pr,L,R,c);
	push_up(p);
}
void update2(int p,int pl,int pr,int L,int R,ll c){
	if(L<=pl&&pr<=R){
		addtag2(p,pl,pr,c);
		return;
	}
	int mid=(pl+pr)>>1;
	push_down(p,pl,pr);
	if(L<=mid) update2(ls(p),pl,mid,L,R,c);
	if(R>mid) update2(rs(p),mid+1,pr,L,R,c);
	push_up(p);
}
ll query(int p,int pl,int pr,int L,int R){
	if(L<=pl&&pr<=R){
		return tree[p];
	}
	push_down(p,pl,pr);
	int mid=(pl+pr)>>1;
	ll maxn=inf;
	if(L<=mid) maxn=max(maxn,query(ls(p),pl,mid,L,R));
	if(R>mid) maxn=max(maxn,query(rs(p),mid+1,pr,L,R));
	return maxn;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>a[i];
	build(1,1,n);
	//cout<<tree[2]<<"\n";
	//cout<<query(1,1,n,1,5)<<"\n";
	while(q--){
		int opt,l,r;ll x;
		cin>>opt>>l>>r;
		if(opt==1){
			cin>>x;
			update2(1,1,n,l,r,x);
		}
		else if(opt==2){
			cin>>x;
			update1(1,1,n,l,r,x);
		}
		else cout<<query(1,1,n,l,r)<<"\n";
	}
	return 0;
}
