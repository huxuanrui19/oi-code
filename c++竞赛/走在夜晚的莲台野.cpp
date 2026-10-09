#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long x,y,z;
		cin>>x>>y>>z;
		long long cnt;
		if(z>=x)
		{
			cnt=x*(z-1+z-x)/2+(z-x);
		}
		else
		{
			cout<<"Merry"<<endl;
			continue;
		}
		if(cnt>=y)
		{
			cout<<"Renko"<<endl;
		}
		else
		{
			cout<<"Merry"<<endl;
		}
	}
	return 0;
}
