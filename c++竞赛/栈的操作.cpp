#include<iostream>
using namespace std;
const int mod=1e6+7;
typedef long long ll;
int main()
{
	ll n;
	cin>>n;
	ll ans=0,cnt=1,i=1;
	while(n>0)
	{
		ans=(ans+min(n,i)*cnt)%mod;
		cnt=cnt*2%mod;
		n-=i;
		i++;
	}
	cout<<ans%mod;
	return 0;
}
