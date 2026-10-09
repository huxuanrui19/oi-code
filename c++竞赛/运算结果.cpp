#include<bits/stdc++.h>
#define lb lower_bound
#define ub upper_bound
using namespace std;
typedef long long ll;
const int N=1e5+10;
ll a[N],b[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	ll ans=0;
	for(ll i=1;i<=10;i++){
		ll tmp=pow(10ll,i);
		memset(b,0,sizeof(b));
		for(int j=1;j<=n;j++){
			b[j]=a[j]%tmp;
		}
		sort(b+1,b+n+1);
		for(int j=1;j<n;j++){
			ll tar=tmp-b[j];
			ll l=j,r=lb(b+1,b+n+1,tar)-b-1;
			ans+=n-max(l,r);
		}
	}
	cout<<ans;
	return 0;
}
