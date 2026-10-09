#include<bits/stdc++.h>
#define ls(p) (p)<<1 
#define rs(p) (p)<<1|1
using namespace std;
typedef long long ll;
const int N=5e5+10,M=1e6+10;
struct tree{
	ll sum,cost;
}tree[M];
ll cnt=0,cur=0,n,m,p;
struct node{
	ll pos,type;
	bool operator <(const node &x) const{
		return pos<x.pos;
	}
}a[N<<1];
void push_up(int p){
	tree[p].sum=tree[ls(p)].sum+tree[rs(p)].sum;
	tree[p].cost=tree[ls(p)].cost+tree[rs(p)].cost;
}
void update(int p)
struct sta{
	ll pos,b,c;
}arr[N];
ll sum[N];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m>>p;
	for(int i=1;i<=n;i++){
		int pos;
		cin>>pos>>sum[i];
		a[++cnt]={pos,1};
	}
	for(int i=1;i<=n;i++) sum[i]+=sum[i-1];
	for(int i=1;i<=m;i++){
		cin>>arr[i].pos>>arr[i].b>>arr[i].c;
		a[++cnt]={arr[i].pos,0};
	}
	sort(a+1,a+cnt+1);
	for(int i=1;i<=cnt;i++){
		cur+=a[i].type;
		if(a[i].type==0){
			update()
		}
	}
	return 0;
}

