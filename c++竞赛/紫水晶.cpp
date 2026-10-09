#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int q;
	cin>>q;
	while(q--)
	{
		ll op,n,x;
		cin>>op>>n>>x;
		if(op==1)
		{
			if(x<n-1)
			{
				cout<<"-1";
			}
			else
			{
				ll m=x-(n-2);
				if(m>INT_MAX)
				{
					cout<<"-1";
				}
				else
				{
					cout<<m<<" "<<m<<" ";
					for(int i=1;i<=n-2;i++)
					{
						cout<<"1"<<" ";
					}
				}
			}
		}
		else
		{
			if(x<n-1)
			{
				cout<<"-1";
			}
			else
			{
				ll m=x-(n-2);
				if(m>INT_MAX)
				{
					cout<<"-1";
				}
				else
				{
					cout<<m<<" ";
					for(int i=1;i<n;i++)
					{
						cout<<"1 ";
					}
				}
			}
		}
		cout<<endl;
	}
	return 0;
}
