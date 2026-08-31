#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e4+10,A=6e2+10;
const ll inf=1e18;
ll n,a[N],d[N],dp[N*A];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=2;i<=n;i++) d[i-1]=a[i]-a[i-1];
	sort(d+1,d+n);
	ll s=0,mx=0;
	fill(dp,dp+N*A,inf);dp[0]=0;
	for(ll i=1;i<=n-1;i++){
		if(d[i]==0) continue;
		s+=d[i];
		for(ll j=mx;j>=0;j--){
			if(dp[j]==inf) continue;
			dp[j+s]=min(dp[j+s],dp[j]+s*s);
			dp[j+i*d[i]]=min(dp[j+i*d[i]],dp[j]+2*j*d[i]+i*d[i]*d[i]);
			mx=max(mx,max(j+s,j+i*d[i]));
			dp[j]=inf;
		}
	}
	ll ans=inf;
	for(ll i=0;i<=mx;i++){
		if(dp[i]>=inf) continue;
		ans=min(ans,n*dp[i]-i*i);
	}
	cout<<ans;
	return 0;
}