#include<bits/stdc++.h>
using namespace std;
int l[int(2e6+6)];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int t;
		double a;
		cin>>a>>t;
		for(int j=1;j<=t;j++)
		{
			int cnt=int(a*double(j));
			l[cnt]^=1;
		}
	}
	int ans=1;
	while(!l[ans])
	{
		ans++;
	}
	cout<<ans;
}
