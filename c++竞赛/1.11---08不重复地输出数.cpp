#include<bits/stdc++.h>
using namespace std;
int a[int(1e5+5)];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	a[0]=INT_MAX;
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=a[i-1])
		{
			cout<<a[i]<<" ";
		}
	}
	return 0;
}
