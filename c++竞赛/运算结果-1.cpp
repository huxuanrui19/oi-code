#include<bits/stdc++.h>
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
	for(int j=0;j<=9;j++){
		ll cnt=pow(10,j);
		for(int i=1;i<=n;i++){
			b[i]=a[i]%cnt;
		}
		sort(b+1,b+n+1);
		for(int i=1;i<=n;i++){
			ll pos=lower_bound(b+i+1,b+n+1,cnt-b[i])-b;
			pos=n+1-pos;
			ans+=pos;
		}
	}
	cout<<ans;
	return 0;
}

