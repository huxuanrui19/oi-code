#include<bits/stdc++.h>
using namespace std;
int main()
{
	int k,flag=0;
	cin>>k;
	for(int i=10000;i<=30000;i++)
	{
		int a1=i%1000;
		int a2=i/10%1000;
		int a3=i/100;
		if(a1%k==0&&a2%k==0&&a3%k==0)
		{
			flag=1;
			cout<<i<<endl;
		}
	}
	if(!flag)
	{
		cout<<"No";
	}
	return 0;
}
