#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10;
ll a[N],sum[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		sum[i]+=sum[i-1];
	} 
	while(q--){
		ll t;
		cin>>t;
		ll l=0,r=n;
		while(l<r){
			ll mid=(l+r+1)>>1;
			if(sum[mid]<=t){
				l=mid;
			}
			else{
				r=mid-1;
			}
		}
		cout<<l<<'\n';
	}
	return 0;
}
