#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
int main()
{
	ll n,x,y;
	cin>>n>>x>>y;
	int sh,ni;
	if(x<y)
	{
		sh=y-x;
	}
	else
	{
		sh=y+n-x;
	}
	if(x>y)
	{
		ni=x-y;
	}
	else
	{
		ni=x+n-y;
	}
	if(sh<ni)
	{
		cout<<"Clockwise Loop";
	}
	else if(sh>ni)
	{
		cout<<"Counter-clockwise Loop";
	}
	else
	{
		cout<<"\""<<"Wonderful"<<"\"";
	}
	return 0;
}
