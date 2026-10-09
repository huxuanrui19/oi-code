#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,k;
	cin>>n>>m>>k;
	int lo=(n+1)/2,hs=lo-k/2,hx=lo+k/2,jd=m-n/2;
	for(int i=1;i<=n/2;i++)
	{
		if(i<hs)
		{	
			for(int j=1;j<=m;j++)
			{
				if(j>=jd&&j<=jd+i-1)
				{
					cout<<"#";
				}
				else
				{
					cout<<".";
				}
			}
		}
		else
		{
			for(int j=1;j<=m;j++)
			{
				if(j<=jd+i-1)
				{
					cout<<"#";
				}
				else
				{
					cout<<".";
				}
			}
		}
		cout<<endl;
	}
	for(int j=1;j<=m;j++)
	{
		cout<<"#";
	}
	cout<<endl;
	for(int i=n/2+2;i<=n;i++)
	{
		if(i>hx)
		{	
			for(int j=1;j<=m;j++)
			{
				if(j>=jd&&j<=jd+n/2-(i-(n/2+2)+1))
				{
					cout<<"#";
				}
				else
				{
					cout<<".";
				}
			}
		}
		else
		{
			for(int j=1;j<=m;j++)
			{
				if(j<=jd+n/2-(i-(n/2+2)+1))
				{
					cout<<"#";
				}
				else
				{
					cout<<".";
				}
			}
		}
		cout<<endl;
	}
	return 0;
}
