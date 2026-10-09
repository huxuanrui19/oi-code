#include<iostream>
using namespace std;
int main()
{
	int n,md=0,d=0;
	cin>>n;
	while(n)
	{
		d++;
		if(n%3==1&&(!md))
		{
			md=d;
		}
		if(n%3)
		{
			n-=n/3+1;
		}
		else
		{
			n-=n/3;
		}
	}
	cout<<d<<" "<<md;
	return 0;
}
