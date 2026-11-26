#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
ll n,k,a[N];
int main(){
	//freopen("twoday.in","r",stdin);
	//freopen("twoday.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	ll res=0,ans=0;
	for(int i=1;i<=n;i++){
		ll num=(res+a[i])/k;
		ans+=num;
		if(res>=num*k) res=a[i];
		else res=res+a[i]-num*k;
	}
	cout<<ans;
	return 0;
}
