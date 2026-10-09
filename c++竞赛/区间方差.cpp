#include<bits/stdc++.h>
#define ls(p) (p)<<1
#define rs(p) (p)<<1|1
using namespace std;
typedef long long ll;
const int N=1e5+10;
const ll mod=1e9+7;
inline ll qp(ll n,ll k){
	ll sum=1;
	while(k){
		if(k&1) sum=sum*n%mod;
		n=n*n%mod;
		k>>=1;
	}
	return sum;
}
ll n,m,b[N],tree1[N<<2],tree2[N<<2];
void push_up(int p){
	tree1[p]=(tree1[ls(p)]+tree1[rs(p)])%mod;
	tree2[p]=(tree2[ls(p)]+tree2[rs(p)])%mod;
}
void build(int p,int pl,int pr){
	if(pl==pr){
		tree1[p]=b[pl];
		tree2[p]=b[pl]*b[pl]%mod;
		return;
	}
	int mid=(pl+pr)>>1;
	build(ls(p),pl,mid);
	build(rs(p),mid+1,pr);
	push_up(p);
}
void update(int p,int pl,int pr,int pos,ll val){
	if(pl==pr){
		tree1[p]=val;
		tree2[p]=val*val%mod;
		return;
	}
	int mid=(pl+pr)>>1;
	if(mid>=pos) update(ls(p),pl,mid,pos,val);
	else update(rs(p),mid+1,pr,pos,val);
	push_up(p);
}
ll query1(int p,int pl,int pr,int L,int R){
	if(L<=pl&&R>=pr) return tree1[p];
	int mid=(pl+pr)>>1;ll ans=0;
	if(mid>=L) ans+=query1(ls(p),pl,mid,L,R);
	if(mid<R)  ans+=query1(rs(p),mid+1,pr,L,R);
	ans%=mod;return ans;
}
ll query2(int p,int pl,int pr,int L,int R){
	if(L<=pl&&R>=pr) return tree2[p];
	int mid=(pl+pr)>>1;ll ans=0;
	if(mid>=L) ans+=query2(ls(p),pl,mid,L,R);
	if(mid<R)  ans+=query2(rs(p),mid+1,pr,L,R);
	ans%=mod;return ans;
}
inline ll cal(int l,int r){
	ll e1=query1(1,1,n,l,r)*qp(r-l+1,mod-2)%mod;
	ll e2=query2(1,1,n,l,r)*qp(r-l+1,mod-2)%mod;
	ll d=((e2-e1*e1%mod)%mod+mod)%mod;
	return d;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>b[i];
	build(1,1,n);
	for(int i=1;i<=m;i++){
		int c,x,y;cin>>c>>x>>y;
		if(c==1) update(1,1,n,x,y);
		else cout<<cal(x,y)<<"\n";
	}
	return 0;
}
