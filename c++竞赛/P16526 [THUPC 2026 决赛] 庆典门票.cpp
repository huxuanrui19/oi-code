#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10;
ll n;
ll d(ll n){
	ll ans=0;
	for(int i=1;i*i<=n;i++){
        if(n%i!=0) continue;
		if(i==n/i) ans++;
		else ans+=2;
	}
	return ans;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen("tic.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	ll T;cin>>T;
	while(T--){
		cin>>n;
		ll ans=0;
		vector<ll> v;
		vector<ll> u;
		for(ll i=2;i*i<=n;i++){
			ll cur=n;
			while(cur){
				v.push_back(cur%i);cur/=i;
			}
			ll lst=0,len=0;
			for(int j=0;j<v.size();j++){
				if((j!=0&&v[j]==lst)||(j==0)) len++,lst=v[j];
				else{
					u.push_back(len);len=1;lst=v[j];
				}
			}
			if(len!=0) u.push_back(len);
			ll gcd=0;
			for(auto j:u){
				gcd=__gcd(gcd,j);
			}
			ans+=d(gcd)-1;
			v.clear();u.clear();
		}//O(sqrt(n)logn)
		for(ll i=1;i*i<=n;i++){
			if(n%i!=0) continue;
			ll num1=i-1,num2=n/i;
			if(num2<num1) ans++;
			num1=n/i-1;num2=i;
			if(num2<num1) ans++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
