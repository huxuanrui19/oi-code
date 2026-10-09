#include<bits/stdc++.h>
using namespace std;
int main()
{
	int maxn=-1,k=0;
	for(int i=1;i<=7;i++)
	{
		int a,b;
		cin>>a>>b;
		if(maxn<(a+b))
		{
			maxn=a+b;
			k=i;
		}
	}
	if(maxn>8)
	{
		cout<<k;
	}
	else
	{
		cout<<"0";
	}
	return 0;
}
