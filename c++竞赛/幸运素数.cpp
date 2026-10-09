#include<bits/stdc++.h>
using namespace std;
int a[10005];
int s(int n)
{
	if(n==2||n==3)
	{
		return 1;
	}
	for(int i=2;i<=sqrt(n);i++)
	{
		if(n%i==0)
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
	int n,m;
	cin>>m>>n;
	a[1]=0;
	for(int i=2;i<10000;i++)
	{
		a[i]=s(i);
	}
	int res=0;
	for(int i=m;i<=n;i++)
	{
		int j=i;
		int flag=0;
		while(j)
		{
			if(!a[j])
			{
				flag=1;
			}
			j/=10;
		}
		if(!flag)
		{
			cout<<i<<endl;
		}
	}
	return 0;
}
