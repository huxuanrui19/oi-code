#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		int c1,c2,c3,d1,d2,d3;
		cin>>c1>>c2>>c3>>d1>>d2>>d3;
		if(c1>d2)
		{
			cout<<"C"<<endl;
			continue;
		}
		else if(c3>d1)
		{
			cout<<"C"<<endl;
			continue;
		}
		d1-=c3;
		d2-=c1;
		if(c2<d1)
		{
			cout<<"D"<<endl;
		}
		else if(c1<d3)
		{
			cout<<"D"<<endl;
		}
		else
		{
			cout<<"E"<<endl;
		}
	}
	return 0;
}
