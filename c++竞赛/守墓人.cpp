#include<bits/stdc++.h>
#define ls(p) (p)<<1
#define rs(p) (p)<<1|1
using namespace std;
typedef long long ll;
const int N=2e5+10;
ll n,f,tree[N<<2],tag[N<<2],a[N];
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
	tree[p]+=(pr-pl+1)*c;
}
void push_down(int p,int pl,int pr){
	if(tag[p]){
		int mid=(pl+pr)>>1;
		addtag(ls(p),pl,mid,tag[p]);
		addtag(rs(p),mid+1,pr,tag[p]);
		tag[p]=0;
	}
}
void update_range(int p,int pl,int pr,int L,int R,int c){
	if(L<=pl&&pr<=R){
		addtag(p,pl,pr,c);
		return;
	}
	push_down(p,pl,pr);
	int mid=(pl+pr)>>1;
	if(L<=mid) update_range(ls(p),pl,mid,L,R,c);
	if(mid<R) update_range(rs(p),mid+1,pr,L,R,c);
	push_up(p);
}
ll query_range(int p,int pl,int pr,int L,int R){
	if(L<=pl&&pr<=R){
		return tree[p];
	}
	int mid=(pl+pr)>>1;
	ll sum=0;
	push_down(p,pl,pr);
	if(L<=mid) sum+=query_range(ls(p),pl,mid,L,R);
	if(mid<R) sum+=query_range(rs(p),mid+1,pr,L,R);
	return sum;
}
void update_node(int p,int pl,int pr,int pos,ll c){
	if(pl==pr){
		tree[p]+=c;
		return;
	}
	push_down(p,pl,pr);
	int mid=(pl+pr)>>1;
	if(pos<=mid) update_node(ls(p),pl,mid,pos,c);
	else update_node(rs(p),mid+1,pr,pos,c);
	push_up(p);
}
ll query_node(int p,int pl,int pr,int pos){
	if(pl==pr){
		return tree[p];
	}
	int mid=(pl+pr)>>1;
	push_down(p,pl,pr);
	if(pos<=mid) return query_node(ls(p),pl,mid,pos);
	else return query_node(rs(p),mid+1,pr,pos); 
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n>>f;
	for(int i=1;i<=n;i++) cin>>a[i];
	build(1,1,n);
	for(int i=1;i<=f;i++){
		int op,l,r,k;
		cin>>op;
		if(op==1){
			cin>>l>>r>>k;
			update_range(1,1,n,l,r,k);
		}
		else if(op==2){
			cin>>k;
			update_node(1,1,n,1,k);
		}
		else if(op==3){
			cin>>k;
			update_node(1,1,n,1,-k);
		}
		else if(op==4){
			cin>>l>>r;
			cout<<query_range(1,1,n,l,r)<<"\n";
		}
		else{
			cout<<query_node(1,1,n,1)<<"\n";
		}
	}
	//cout<<tree[1];
	//for(int i=1;i<=n;i++) cout<<query_node(1,1,n,i)<<" ";
	return 0;
}

