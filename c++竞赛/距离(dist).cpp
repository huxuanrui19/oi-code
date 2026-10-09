#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
ll n,ans=0,a[N],b[N],x[N],y[N],sum[N];
ll cal(ll a[]){
	sort(a+1,a+n+1);
	memset(sum,0,sizeof(sum));
	ll cnt=0;
	for(int i=1;i<=n;i++) sum[i]=a[i]+sum[i-1];
	for(int i=1;i<=n;i++) cnt+=a[i]*i-sum[i]+sum[n]-sum[i]-a[i]*(n-i);
	return cnt;
} 
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i];
	for(int i=1;i<=n;i++){
		x[i]=a[i]+b[i];
		y[i]=a[i]-b[i];
	}
	ans+=cal(a);ans+=cal(b);ans-=(cal(x)+cal(y))/2;
	cout<<ans;
	return 0;
}

