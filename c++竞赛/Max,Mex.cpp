#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll n,sum=0,zero=0,one=0,tmp;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>tmp;
		if(tmp==1)
		{
			one++;
		}
		if(tmp==0)
		{
			zero++;
		}
		sum+=tmp;
	}
	//cout<<one<<" "<<zero;
	if(one==1)
	{
		sum+=2*zero;
	}
	else if(one>1)
	{
		sum+=2*zero+one-1;
	}
	else if(zero>1)
	{
		sum+=(2*zero-1);
	}
	else
	{
		sum+=zero;
	}
	printf("%ld",sum);
	return 0;
}
