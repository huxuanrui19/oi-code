#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
#define lowbit(x) ((x)&-(x))
ll tree1[N]={0},tree2[N],a[N];
void update1(ll x,ll d){
	while(x<N){
		tree1[x]+=d;
		x+=lowbit(x);
	}
}
void update2(ll x,ll d){
	while(x<N){
		tree2[x]+=d;
		x+=lowbit(x);
	}
}
ll sum1(int x){
	ll ans=0;
	while(x>0){
		ans+=tree1[x];
		x-=lowbit(x);
	}
	return ans;
}
ll sum2(int x){
	ll ans=0;
	while(x>0){
		ans+=tree2[x];
		x-=lowbit(x);
	}
	return ans;
}
ll query(ll x,ll y){
	x--;
	return y*sum1(y)-sum2(y)-x*sum1(x)+sum2(x);
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
		update1(i,a[i]-a[i-1]);
		update2(i,(i-1)*(a[i]-a[i-1]));
	}
	for(int i=1;i<=m;i++){
		ll op,x,y;
		cin>>op>>x>>y;
		if(op==1){
			ll k;
			cin>>k;
			update1(x,k);
			update2(x,k*(x-1));
			update1(y+1,-k);
			update2(y+1,-k*y);
		}
		else{
			cout<<query(x,y)<<"\n";
		}
	}
	return 0;
}

