#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll phi(ll x){
	ll ans=x;
	for(ll i=2;i<=sqrt(x);i++){
		if(x%i==0){
			ans=ans/i*(i-1);
			while(x%i==0){
				x/=i;
			}
		}
	}
	if(x!=1){
		ans=ans/x*(x-1);
	}
	return ans;
}
int main(){
	ll n;
	cin>>n;
	ll ans=0;
	for(ll i=1;i<=sqrt(n);i++){
		if(n%i==0){
			ans+=phi(n/i)*i+phi(i)*(n/i);
		}
		if(i*i==n)
		{
			ans-=phi(n/i)*i; 
		}
	}
	cout<<ans;
	return 0;
}
