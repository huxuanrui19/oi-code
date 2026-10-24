#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
#define lowbit(x) ((x)&-(x))
ll tree[N]={0},a[N];
void update(ll x,ll d){
	while(x<N){
		tree[x]+=d;
		x+=lowbit(x);
	}
}
ll sum(int x){
	ll ans=0;
	while(x>0){
		ans+=tree[x];
		x-=lowbit(x);
	}
	return ans;
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
		update(i,a[i]-a[i-1]);
	}
	for(int i=1;i<=m;i++){
		int op;
		cin>>op;
		if(op==1){
			ll x,y,k;
			cin>>x>>y>>k;
			update(x,k);
			update(y+1,-k);
		}
		else{
			ll x;
			cin>>x;
			cout<<sum(x)<<'\n';
		}
	}
	return 0;
}

