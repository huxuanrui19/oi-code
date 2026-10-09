#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
ll qp(ll b,ll k,ll p){
	ll sum=1;
	while(k){
		if(k&1) sum=sum*b%p;
		b=b*b%p;
		k>>=1;
	}
	return sum;
}
ll bsgs(ll p,ll b,ll n){
	if(n==1) return 0;
	if(b%p==0&&) return -1
	unordered_map<ll,ll> mp;ll m=sqrt(p)+1;
	mp[n]=0;ll tmp=1;
	for(int j=1;j<=m-1;j++){
		tmp=tmp*b%p;
		mp[n*tmp%p]=j;
	}
	tmp=tmp*b%p;b=tmp;
	for(int i=1;i<=m;i++){
		if(mp.count(b)){
			return m*i-mp[b];
		}
		b=b*tmp%p;
	}
	return -1;
}
int main(){
	ll p,b,n;
	cin>>p>>b>>n;
	ll t=bsgs(p,b,n);
	if(t==-1) cout<<"no solution";
	else cout<<t;
}
