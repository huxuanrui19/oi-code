#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll ax,ay,az,bx,by,bz;
	cin>>ax>>ay>>az>>bx>>by>>bz;
	ll ax2,ay2,az2,bx2,by2,bz2;
	cin>>ax2>>ay2>>az2>>bx2>>by2>>bz2;
	if(ax==bx&&ay==by&&az==bz)
	{
		cout<<"0";
		return 0;
	}
	if(bx<ax2||by<ay2||bz<az2)
	{
		cout<<"0";
		return 0;
	}
	ll v=(bx-ax2+1)*(by-ay2+1)*(bx-ay2+1);
	cout<<max(v,0ll);
	return 0;
}
