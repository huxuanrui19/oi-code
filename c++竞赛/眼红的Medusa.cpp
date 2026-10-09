#include<bits/stdc++.h>
using namespace std;
int a[int(1e5+5)],b[int(1e5+5)];
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=m;i++)
	{
		cin>>b[i];
	}
	sort(b,b+m+1);
	for(int i=1;i<=n;i++)
	{
		if(a[i]==b[lower_bound(b+1,b+m+1,a[i])-b])
		{
			cout<<a[i]<<" ";
		}
	}
	return 0;
}
