#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int f(int x)
{
	int res=x;
	while(x>=3)
	{
		int m=x/3;
		res+=m;
		x%=3;
		x+=m;
	}
	return res;
}
int main()
{
	int n;
	cin>>n;
	int l=1,r=n,mid;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(f(mid)<n)
		{
			l=mid+1;
		}
		else if(f(mid)>n)
		{
			r=mid-1;
		}
		else
		{
			break;
		}
	}
	cout<<f(0)<<" ";
	cout<<mid;
	return 0;
}
