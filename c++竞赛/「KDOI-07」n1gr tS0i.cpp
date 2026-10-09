#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=998244353;
inline ll qp(ll a,ll b){
	ll sum=1;
	while(b){
		if(b&1) sum=sum*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return sum;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		if(n==2) cout<<"1\n";
		else if(n==3) cout<<"4\n";
		else cout<<qp(2,n)<<"\n";
	}
	return 0;
}

