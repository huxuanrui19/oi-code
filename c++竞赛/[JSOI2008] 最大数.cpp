#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10,M=25;
ll cnt=0,st[N][M];
void add_back(ll x){
	++cnt;
	st[cnt][0]=x;
	for(int i=1;(1<<i)<=cnt;i++){
		int tmp=cnt-(1<<i)+1;
		st[tmp][i]=max(st[tmp][i-1],st[tmp+(1<<(i-1))][i-1]);
	}
}
ll query(ll l,ll r){
	ll p=log2(r-l+1);
	return max(st[l][p],st[r-(1<<p)+1][p]);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,d,t=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		char op;
		ll x;
		cin>>op>>x;
		if(op=='A'){
			add_back((x+t)%d);
		}
		else{
			cout<<query(cnt-x+1,cnt)<<"\n";
			t=query(cnt-x+1,cnt);
		}
	}
	return 0;
}

