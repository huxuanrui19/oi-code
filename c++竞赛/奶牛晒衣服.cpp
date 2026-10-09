#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
ll n,a,b,w[N];
bool check(ll x){
	ll num=0;
	for(int i=1;i<=n;i++){
		if(w[i]<=a*x){
			continue;
		}
		else{
			ll tmp=w[i]-a*x;
			if(tmp%b==0) num+=tmp/b;
			else num+=tmp/b+1;
		}
	}
	if(num<=x) return 1;
	return 0;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n>>a>>b;
	for(int i=1;i<=n;i++) cin>>w[i];
	ll l=0,r=1e9,ans=0;
	while(l<=r){
		ll mid=(l+r)>>1;
		if(check(mid)){
			r=mid-1;
			ans=mid;
		}
		else{
			l=mid+1;
		}
	}
	cout<<ans;
	return 0;
}

