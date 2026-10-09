#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll f,s,x;
	cin>>f>>s>>x;
	ll d=s-f;
	ll m=f+d*(x-1);
	ll sum=(f+m)*x/2;
	cout<<sum;
	return 0;
}
