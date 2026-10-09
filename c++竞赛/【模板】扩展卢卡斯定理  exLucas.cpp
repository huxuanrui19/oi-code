#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
ll n,m,p;
ll qp(ll k,ll n,ll mod){
	ll sum=1;
	while(n>0){
		if(n&1) sum=sum*k%mod;
		k=k*k%mod;
		n>>=1;
	}
	return sum;
}
ll exgcd(ll a,ll b,ll &x,ll &y){
	if(b==0){
		x=1;y=0;
		return a;
	}
	ll d=exgcd(b,a%b,y,x);
	y-=a/b*x;
	return d;
}
ll inv(ll n,ll p){
	ll x,y;
	exgcd(n,p,x,y);
	return (x%p+p)%p;
}
ll facp(ll n,ll p,ll pa){
	if(!n) return 1;
	ll ans=1,cnt=1;
	for(ll i=2;i<=pa;i++) if(i%p) cnt=cnt*i%pa;
	ans=qp(cnt,n/pa,pa);
	for(ll i=2;i<=n%pa;i++) if(i%p) ans=ans*i%pa;
	return ans*facp(n/p,p,pa)%pa;
}
ll c(ll n,ll m,ll p,ll pa){
	ll dn=facp(n,p,pa),dm=facp(m,p,pa),dnm=facp(n-m,p,pa),k=0;
	for(ll i=n;i;i/=p) k+=i/p;
	for(ll i=m;i;i/=p) k-=i/p;
	for(ll i=n-m;i;i/=p) k-=i/p;
	if(qp(p,k,pa)==0) return 0;
	return qp(p,k,pa)*dn%pa*inv(dm,pa)%pa*inv(dnm,pa)%pa;
}
ll CRT(vector<pair<ll,ll> > v){
	ll ans=0,n=v.size(),m=1;
	for(int i=0;i<n;i++) m=m*v[i].second;
	for(int i=0;i<n;i++){
		ll inve=inv(m/v[i].second,v[i].second);
		ans=(ans+(m/v[i].second)*inve%m*v[i].first)%m; 
	}
	return (ans+m)%m;
}
ll exlucas(ll n,ll m,ll p){
	ll tmp=p,times=1;
	vector<pair<ll,ll> > pri; 
	for(int i=2;i*i<=p;i++){
		if(tmp%i==0){
			times=1;
			while(tmp%i==0){
				tmp/=i;
				times*=i;
			}
			pri.push_back({i,times});
		}
	}
	if(tmp>1) pri.push_back({tmp,tmp});
	vector<pair<ll,ll> > v;
	for(auto d:pri){
		v.push_back({c(n,m,d.first,d.second),d.second});
	}
	return CRT(v);
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m>>p;
	cout<<exlucas(n,m,p); 
	return 0;
}

