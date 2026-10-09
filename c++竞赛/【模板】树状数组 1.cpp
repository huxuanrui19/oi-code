#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
#define lowbit(x) ((x)&-(x))
ll tree[N]={0};
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
		int tmp;
		cin>>tmp;
		update(i,tmp);
	}
	for(int i=1;i<=m;i++){
		ll op;
		cin>>op;
		if(op==1){
			ll x,k;
			cin>>x>>k;
			update(x,k); 
		}
		else{
			ll f,e;
			cin>>f>>e;
			cout<<sum(e)-sum(f-1)<<'\n';
		}
	}
	return 0;
}

