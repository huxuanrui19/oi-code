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
// b^x (mod p)= n
ll bsgs(ll p,ll b,ll n){
	if(n==1) return 0;
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
}/*
ll bsgs(ll p,ll b,ll n){
	if(n==1) return 0;
	unordered_map<ll,ll> mp;
	ll m=sqrt(p)+1,base=1;
	mp[n]=0;
	for(int i=1;i<m;i++){
		base=base*b%p;
		mp[n*base%p]=i;
	}
	base=base*b%p;ll cnt=base;
	for(int i=1;i<=m;i++){
		if(mp.count(base)){
			return i*m-mp[base];
		}
		base=base*cnt%p;
	}
	return -1;
}*/
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	ll t,k;
	cin>>t>>k;
	while(t--){
		ll y,z,p;cin>>y>>z>>p;
		if(k==1) cout<<qp(y,z,p)<<"\n";
		else if(k==2){
			if(y%p==0){
				if(z%p==0) cout<<"0\n";
				else cout<<"Orz, I cannot find x!\n";
			}
			else cout<<(z*qp(y,p-2,p)%p)<<"\n";
		}
		else{
			ll ans=bsgs(p,y,z);
			if(ans==-1) cout<<"Orz, I cannot find x!\n";
			else cout<<ans<<"\n";
		}
	}
	return 0;
}

