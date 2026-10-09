#include<bits/stdc++.h>
using namespace std;
int main()
{
	int x,c,k;
	cin>>x>>c>>k;
	while(--k)
	{
		x=(x*x+c)%10000;
	}
	cout<<x;
	return 0;
}
