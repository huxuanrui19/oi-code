#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
ll n,m,a[N],sum[N];
bool check(ll x){
	ll minn=(1ll<<62);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i]-x;
		if(i>=m){
			minn=min(minn,sum[i-m]);
			if(sum[i]-minn>=0) return 1;
		}
	}
	return 0;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) a[i]=a[i]*10000;
	ll l=1,r=1e18,ans=0;
	while(l<=r){
		ll mid=(l+r)>>1;
		if(check(mid)){
			l=mid+1;
			ans=mid;
		}else r=mid-1;
	}
	cout<<ans/10;
	return 0;
}

