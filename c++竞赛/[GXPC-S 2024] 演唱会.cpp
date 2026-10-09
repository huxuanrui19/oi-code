#include<bits/stdc++.h>
#define ls(p) (p)<<1
#define rs(p) (p)<<1|1 
using namespace std;
typedef long long ll;
const int N=1e5+10;
ll n,m,a[N],tree1[N<<2],tree2[N<<2];
void push_up(int p){tree1[p]=tree1[ls(p)]+tree1[rs(p)];tree2[p]=max(tree2[ls(p)],tree2[rs(p)]);}
void build(int p,int pl,int pr){
	if(pl==pr){
		tree1[p]=tree2[p]=a[pl];
		return;
	}
	int mid=(pl+pr)>>1;
	build(ls(p),pl,mid);
	build(rs(p),mid+1,pr);
	push_up(p);
}
void update(int p,int pl,int pr,int pos,ll val){
	if(pl==pr){
		tree1[p]=tree2[p]=val;
		return;
	}
	int mid=(pl+pr)>>1;
	if(pos<=mid) update(ls(p),pl,mid,pos,val);
	else update(rs(p),mid+1,pr,pos,val);
	push_up(p);
}
pair<ll,ll> query(int p,int pl,int pr,int L,int R){
	if(L<=pl&&pr<=R) return {tree1[p],tree2[p]};
	int mid=(pl+pr)>>1;
	ll ans1=0,ans2=0;
	pair<ll,ll> a1,a2;
	a1={0,0};a2={0,0};
	if(L<=mid) a1=query(ls(p),pl,mid,L,R);
	if(R>mid) a2=query(rs(p),mid+1,pr,L,R);
	ans2=max(a1.second,a2.second);
	ans1=a1.first+a2.first;
	return {ans1,ans2};
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	build(1,1,n);
	while(m--){
		int op,x,y;
		cin>>op>>x>>y;
		if(op==1){
			pair<ll,ll> a=query(1,1,n,x,y);
			cout<<a.first*a.second<<"\n";
		}
		else update(1,1,n,x,y);
	}
	return 0;
}

