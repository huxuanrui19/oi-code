#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[5005];
int main()
{
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int ans=0;
	for(int l=1;l<=n-k+1;l++)
	{
		int cnt=0;
		for(int i=1;i<l;i++)
		{
			if(a[i]<(99-a[i]))
			{
				cnt++;
			}
		}
		for(int i=l;i<=l+k-1;i++)
		{
			if((a[i]-2)<(101-a[i]))
			{
				cnt++;
			}
		}
		for(int i=l+k;i<=n;i++)
		{
			if(a[i]<(99-a[i]))
			{
				cnt++;
			}
		}
		if((cnt*2)>n)
		{
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
