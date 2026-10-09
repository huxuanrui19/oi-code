#include<iostream>
using namespace std;
int main()
{
	int num=0,ca=0;
	for(int i=1;i<=12;i++)
	{
		int tmp;
		cin>>tmp;
		num+=300;
		num-=tmp;
		if(num<0)
		{
			cout<<"-"<<i;
			return 0;
		}
		ca+=num/100*100;
		num%=100;
	}
	cout<<int(ca*1.2+num);
	return 0;
}
