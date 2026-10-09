#include<bits/stdc++.h>
using namespace std;
int a[25];
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int tmp,ans=0;
	for(int i=1;i<=m;i++)
	{
		cin>>tmp;
		if(tmp==a[lower_bound(a+1,a+n+1,tmp)-a])
		{
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
