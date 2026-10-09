#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll k,n;
	cin>>k>>n;
	if(n<=k) cout<<char('A'+n-1);
	else{
		ll l=1,r=60,ans=0;
		while(l<=r){
			ll mid=(l+r)>>1;
			ll cnt=pow(2,mid)-1;
			ll tar=k*cnt;
			if(tar<=n){
				ans=mid;
				l=mid+1;
			}
			else r=mid-1;
		}
		ll cnt=pow(2,ans)-1;
		ll re=n-k*cnt;
        if(re==0){
            cout<<char('A'+k-1);
            return 0;
        }
        ll cnt2=pow(2,ans);
		re=ceil(double(re)/cnt2);
		cout<<char('A'+re-1);
	} 
	return 0;
}
