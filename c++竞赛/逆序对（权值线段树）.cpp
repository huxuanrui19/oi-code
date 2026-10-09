#include<bits/stdc++.h>
#define ls(p) (p)<<1
#define rs(p) (p)<<1|1
using namespace std;
typedef long long ll;
const int N=5e5+10;
int n,cnt,a[N],b[N];
ll tree[N<<2];
void push_up(int p){
	tree[p]=tree[ls(p)]+tree[rs(p)];
}
void build(int p,int pl,int pr){
	if(pl==pr){
		tree[p]=0;
		return;
	}
	int mid=(pl+pr)>>1;
	build(ls(p),pl,mid);
	build(rs(p),mid+1,pr);
	push_up(p);
}
void update(int p,int pl,int pr,int val,int k){
	if(pl==pr){
		tree[p]+=k;
		return;
	}
	int mid=(pl+pr)>>1;
	if(val<=mid) update(ls(p),pl,mid,val,k);
	else update(rs(p),mid+1,pr,val,k);
	push_up(p);
}
ll query(int p,int pl,int pr,int L,int R){
	if(L<=pl&&pr<=R) return tree[p];
	ll sum=0;
	int mid=(pl+pr)>>1;
	if(L<=mid) sum+=query(ls(p),pl,mid,L,R);
	if(R>mid) sum+=query(rs(p),mid+1,pr,L,R);
	return sum;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	} 
	sort(b+1,b+n+1);
	cnt=unique(b+1,b+n+1)-b-1;
	build(1,1,cnt);
	ll ans=0;
	for(int i=1;i<=n;i++){
		int pos=lower_bound(b+1,b+cnt+1,a[i])-b;
		if(pos!=cnt) ans+=query(1,1,cnt,pos+1,cnt);
		update(1,1,cnt,pos,1); 
	}
	cout<<ans;
	return 0;
}

