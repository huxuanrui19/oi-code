#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3e5+10;
ll lowbit(ll x) {return x&(-x);}
ll t[N],a[N];
void update(ll x,ll d){
	while(x<N){
		t[x]+=d;
		x+=lowbit(x);
	}
}
ll query(ll x){
	ll ans=0;
	while(x){
		ans+=t[x];
		x-=lowbit(x);
	}
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) update(i,a[i]-a[i-1]);
	for(int i=1;i<=n;i++){
		int opt,l,r,c;
		cin>>opt>>l>>r>>c;
		if(opt==0){
			update(l,c);
			update(r+1,-c);
		}
		else if(opt==1){
			cout<<query(r)<<"\n";
		}
	}
	return 0;
}

