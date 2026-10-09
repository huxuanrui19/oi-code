#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
ll a[N]; 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,c;
	cin>>n>>c;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	ll ans=0;
	for(int i=1;i<n;i++){
		int tar=a[i]+c;
		ans+=upper_bound(a+i+1,a+n+1,tar)-lower_bound(a+i+1,a+n+1,tar);
	}
	cout<<ans;
	return 0;
}

