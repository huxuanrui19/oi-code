#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b;
	cin>>a>>b;
	if(a%2==b%2)
	{
		cout<<abs(a-b)/2-1;
	}
	else
	{
		cout<<a/2+b/2;
	}
	return 0;
}
