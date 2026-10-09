#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[int(1e3+5)][int(1e3+5)];
int main()
{
	ll n,x;
	cin>>n>>x;
	ll w,h;
	cin>>w>>h;
	for(int i=1;i<=w*h;i++)
	{
		int p,q,r;
		cin>>p>>q>>r;
		a[p][q]=r;
	}
	if(x==1)
	{
		for(int i=0;i<w;i++)
		{
			ll sum=0;
			for(int j=0;j<h;j++)
			{
				sum+=a[i][j];
			}
			cout<<i<<" "<<sum<<endl;
		}
	}
	if(x==0)
	{
		for(int i=0;i<h;i++)
		{
			ll sum=0;
			for(int j=0;j<w;j++)
			{
				sum+=a[j][i];
			}
			cout<<i<<" "<<sum<<endl;
		}
	}
	return 0;
}
