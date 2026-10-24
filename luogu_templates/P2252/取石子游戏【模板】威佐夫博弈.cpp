#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,m;
	cin>>n>>m;
	long double g=(1.0+sqrtl(5.0))/2.0;
	ll a=min(m,n),k=abs(m-n);
	ll test=ll(k*g);
	if(test==a) cout<<"0";
	else cout<<"1";
	return 0;
}

