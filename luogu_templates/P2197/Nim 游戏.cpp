#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int x=0;
		int tmp;
		cin>>tmp;
		x=tmp;
		for(int i=1;i<n;i++)
		{
			cin>>tmp;
			x=x^tmp;
		}
		if(x)
		{
			cout<<"Yes";
		}
		else
		{
			cout<<"No";
		}
		cout<<endl;
	}
	return 0;
}
