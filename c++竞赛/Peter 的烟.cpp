#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,k;
	cin>>n>>k;
	int res=n;
	while(n>=k)
	{
		int m=n/k;
		res+=m;
		n%=k;
		n+=m;
	}
	cout<<res;
	return 0;
}
