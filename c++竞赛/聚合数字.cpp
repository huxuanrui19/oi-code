#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n;
	cin>>n;
	ll ans=n/9*45;
	n%=9;
	ans+=n*(n+1)/2;
	cout<<ans; 
	return 0;
}

