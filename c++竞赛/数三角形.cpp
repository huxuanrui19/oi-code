#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ll n,m;
	cin>>n>>m;
	ll cnt=(n+1)*(m+1);
	ll ans=cnt*(cnt-1)*(cnt-2)/6;
	ans-=(n+1)*(m+1)*m*(m-1)/6;
	ans-=(m+1)*(n+1)*n*(n-1)/6;
	ll res=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			res+=(n-i+1)*(m-j+1)*(__gcd(i,j)-1)*2;
		}
	}
	ans-=res;
	cout<<ans;
	return 0;
} 
