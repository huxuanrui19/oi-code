#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int a;
		cin>>a;
		int b=sqrt(sqrt(a));
		if(b*b*b*b==a)
		{
			cout<<b;
		}
		else
		{
			cout<<"-1";
		}
		cout<<endl;
	}
}
