#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[int(1e3+5)];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		if(i==1)
		{
			a[i]=1;
		}
		else
		{
			for(int j=1;j<=i/2;j++)
			{
				a[i]+=a[j];
			}
			a[i]+=1;
		}
	}
	cout<<a[n];
	return 0;
}
