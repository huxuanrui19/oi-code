#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=998244353;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll l,r,ans=1,mark=0;
	cin>>l>>r;
	for(ll i=ceil(sqrt(l));i<=floor(sqrt(r));i++){
		ll tmp=i*i,cnt=0,flag=0;
		while(tmp){
			cnt+=tmp%10;
			tmp/=10;
		}
		if(cnt==1) continue;
		for(ll j=2;j*j<=cnt;j++){
			if(cnt%j==0){
				flag=1;
				break;
			}
		}
		if(flag) continue;
        mark=1;
		ans=ans*((i*i)%mod)%mod;
	}
	cout<<ans*mark;
	return 0;
}

