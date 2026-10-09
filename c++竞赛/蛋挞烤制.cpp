#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll ve,vm,vt;
	ll e,m,t;
	cin>>ve>>vm>>vt>>e>>m>>t;
	ll num=ceil(double(e*ve+m*vm)/double(vt));
	ll ti=ceil(double(num)/double(t));
	cout<<ti;
	return 0;
}
