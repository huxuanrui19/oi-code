#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int a,p;
		cin>>a>>p;
		if(p>=16&&p<=20)
		{
			cout<<a;
		}
		else if(p<16)
		{
			cout<<max((a-10),0);
		}
		else
		{
			cout<<max((a-(p-20)),0);
		}
		cout<<endl;
	}
	return 0;
}
