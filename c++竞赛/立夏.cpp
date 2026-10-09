#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long a;
		cin>>a;
		if(a%3==2)
		{
			cout<<"0";
		}
		else
		{
			long long cnt=1;
			a/=3;
			while(a)
			{
				if(a%3==1)
				{
					cnt*=2;
				}
				a/=3;
			}
			cout<<cnt;
		}
		cout<<endl;
	}
}
