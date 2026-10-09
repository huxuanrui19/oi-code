#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
string s;
ll mod,n,ans,a[N];
ll qp(ll a,ll b){
	ll sum=1;
	while(b){
		if(b&1) sum=sum*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return sum;
}
map<ll,ll> mp;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>s>>mod;
	n=s.size();
	if(mod==2||mod==5){
		for(ll i=0;i<n;i++){
			if((s[i]-'0')%mod==0){
				ans+=i+1;
			}
		}
	}
	else{
		mp[0]=1;
		for(int i=0;i<n;i++){
			a[i+1]=(a[i]*10+(s[i]-'0'))%mod;
			ll cnt=a[i+1]*qp(10,n-i)%mod;
			ans+=mp[cnt];
			mp[cnt]++;
		}
	}
	cout<<ans;
	return 0;
}

