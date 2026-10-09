#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int t[n+5],f[n+5]={0};
	for(int i=1;i<=n;i++)
	{
		cin>>t[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(t[i]<=15)
		{
			cout<<t[i]<<" ";
			f[i]=1;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(!f[i])
		{
			cout<<t[i]<<" ";
		}
	}
	return 0;
}
