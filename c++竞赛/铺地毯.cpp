#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N],b[N],g[N],k[N];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i]>>g[i]>>k[i];
	}
	int x,y,ans=0;
	cin>>x>>y;
	for(int i=1;i<=n;i++)
	{
		if(x>=a[i]&&x<=a[i]+g[i]&&y>=b[i]&&y<=b[i]+k[i])
		{
			ans=i;
		}
	}
	if(!ans)
	{
		cout<<"-1";
	}
	else
	{
		cout<<ans;
	}
	return 0;
}
