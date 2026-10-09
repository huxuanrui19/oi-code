#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
const ll mod=998244353; 
int main(){
	ll lll,rrr,ans=0,ans2=0;
	cin>>lll>>rrr;
	lll--;
	for(ll l=1,r;l<=lll;l=r+1){
		if(lll/(lll/l)>lll){
			r=lll;
		}
		else{
			r=lll/(lll/l);
		}
		ans+=(r-l+1)*(lll/l)%mod;
	}
	for(ll l=1,r;l<=rrr;l=r+1){
		if(rrr/(rrr/l)>rrr){
			r=rrr;
		}
		else{
			r=rrr/(rrr/l);
		}
		ans2+=(r-l+1)*(rrr/l)%mod;
	}
	cout<<(ans2-ans+mod)%mod;
	return 0;
}
