#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
ll n,m,p,fac[N]; 
ll fp(ll a,ll b){
	ll sum=1;
	while(b>0){
		if(b&1){
			sum=sum*a%p;
		}
		a=a*a%p;
		b>>=1;
	}
	return sum;
}
void init(){
	
	return;
}
ll inve(int n){
	return fp(fac[n],p-2);
}
ll c(int n,int m){
	if(m>n) return 0;
	return (fac[n]*inve(m))%p*inve(n-m)%p;
}
ll l(int n,int m){
	if(m==0) return 1;
	return l(n/p,m/p)*c(n%p,m%p)%p;
} 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m>>p;
		fac[0]=1;
		for(int i=1;i<=p;i++){
			fac[i]=fac[i-1]*i%p;
		}
		cout<<l(n+m,n)<<endl;
	}
	return 0;
}

