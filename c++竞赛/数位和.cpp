#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n,maxn=-1;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		long long tmp,sum=0;
		cin>>tmp;
		while(tmp)
		{
			sum+=tmp%10;
			tmp/=10;
		}
		maxn=max(maxn,sum);
	}
	cout<<maxn;
	return 0;
}
