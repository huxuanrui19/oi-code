#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll k;
	cin>>k;
	if(k==floor(sqrt(k))*floor(sqrt(k))&&k>=0)
	{
		cout<<int(sqrt(k));
		return 0;
	}
	ll minn=1e12+5;
	//cout<<((-6)%2)<<endl;
	for(ll i=-sqrt(abs(k));i<=sqrt(abs(k));i++)
	{
		if(i==0)
		{
			i++;
		}
		if(k%i==0)
		{
			ll j=k/i;
			if((j%2+2)%2==(i%2+2)%2)
			{
				minn=min(minn,abs(i+j)/2);
			}
		}
	}
	//cout<<minn<<endl;
	if(minn==1e12+5)
	{
		cout<<"none";
	}
	else
	{
		cout<<minn;
	}
	return 0;
}
