#include<bits/stdc++.h>
using namespace std;
int a[int(1e5+5)];
int check(int ii,int tt)
{
	int num[6];
	int i=ii;
	int t=tt;
	memset(num,-1,sizeof(num));
	for(int j=1;j<=5;j++)
	{
		if(i%10==t%10)
		{
			num[j]=0;
		}
		else
		{
			num[j]=(i%10+10-t%10)%10;
		}
		i/=10;
		t/=10;
	}
	int k=0;
	for(int j=1;j<=5;j++)
	{
		if(num[j]==0)
		{
			k++;
		}
		if(k>=4)
		{
			return 1;
		}
	}
	if(k>=4)
	{
		return 1;
	}
	if(k==3)
	{
		int cur=0;
		for(int j=1;j<=4;j++)
		{
			if(num[j]==num[j+1]&&(num[j]!=0))
			{
				cur++;
			}
		}
		if(cur==1)
		{
			return 1;
		}
	}
	return 0;
}
int main()
{
	int n,cnt=0;
	cin>>n;
	for(int i=0;i<=99999;i++)
	{
		a[i]=1;
	}
	while(n--)
	{
		int t=0;
		for(int i=1;i<=5;i++)
		{
			int tmp;
			cin>>tmp;
			t*=10;
			t+=tmp;
		}
		for(int i=0;i<=99999;i++)
		{
			if(a[i]==1)
			{
				if(i==t||check(i,t)==0)
				{
					a[i]=0;
				}
			}
		}
	}
	for(int i=0;i<=99999;i++)
	{
		if(a[i]==1)
		{
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
