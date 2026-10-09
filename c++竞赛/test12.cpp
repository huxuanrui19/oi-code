#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
const int INS=20101009;
typedef long long ll;
ll qp(ll k,ll n)
{
	ll sum=1;
	while(n>0)
	{
		if(n&1)
		{
			sum=sum*k%INS;
		}
		k=k*k%INS;
		n>>=1;
	}
	return sum;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<qp(2,INS-2);
	return 0;
}

