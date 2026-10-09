#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
string s;
ll a[N];
unordered_map<ll,ll> mp;
ll qp(ll n,ll k,ll mod){
	ll sum=1;
	if(k<0) return 1;
	while(k){
		if(k&1) sum=sum*n%mod;
		n=n*n%mod;
		k>>=1;
	}
	return sum;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>s;
	ll mod,ans=0;
	cin>>mod;
	if(mod==2||mod==5){
		for(int i=0;i<s.size();i++){
			if((s[i]-'0')%mod==0){
				ans+=i+1;
			}
		}
		cout<<ans;
		return 0;
	}
	s=' '+s;
	mp[0]=1;
	for(int i=1;i<s.size();i++){
		a[i]=(a[i-1]*10+(s[i]-'0'))%mod;
		ll cnt=a[i]*qp(10,s.size()-i-1,mod)%mod; 
		ans+=mp[cnt];
		mp[cnt]++;
	}
	cout<<ans;
	return 0;
}

