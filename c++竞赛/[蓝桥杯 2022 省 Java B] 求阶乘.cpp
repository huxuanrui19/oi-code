#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
ll k;
ll check(ll n){
	ll ans=0,x=5;
	while(n/x>0){
		ans+=n/x;
		x*=5;
	}
	return ans;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>k;
	ll l=1,r=5*k,ans=0;
	while(l<=r){
		ll mid=(l+r)>>1;
		ll x=check(mid);
		if(x==k){
			ans=mid;
			r=mid-1;
		}
		else if(x<k) l=mid+1;
		else r=mid-1;
	}
	if(check(ans)==k) cout<<ans;
	else cout<<"-1";
	return 0;
}

