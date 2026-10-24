#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INS=1e5+10;
ll getphi(ll m){
	ll ans=m,n=m;
	for(ll i=2;i*i<=n;i++){
		if(m%i==0){
			ans=ans/i*(i-1);
			while(m%i==0){
				m/=i;
			}
		}
	}
	if(m!=1){
		ans=ans/m*(m-1);
	}
	return ans;
}
template < typename T >
void read(T &x,ll mod){
	int g=0;x=0;int f=1;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f*=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=(x<<1)+(x<<3)+(ch&15);
		if(x>=mod) g=1;
		x%=mod;
		ch=getchar(); 
	}
	x*=f;
	if(g) x+=mod;
}
ll qp(ll k,ll n,ll INS)
{
	ll sum=1;
	while(n>0)
	{
		if(n&1)
		{
			sum=sum*k%INS;
		}
		k=k*k%INS;
		n>>=1;
	}
	return sum;
}
int main(){
	ll a,m;
	cin>>a>>m;
	ll mp=getphi(m);
	ll b;
	read(b,mp);
	cout<<qp(a,b,m);
	return 0;
}

