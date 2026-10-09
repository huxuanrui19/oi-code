#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n;
	cin>>n;
	long long res=0,f[n+5];
	for(long long i=n;i>=1;i--)
	{
		f[i]=floor(n/i)*floor(n/i);
		for(long long j=i*2;j<=n;j+=i)
		{
			f[i]-=f[j];
		}
		res+=f[i]*i;
	}
	cout<<res;
	return 0;
}
