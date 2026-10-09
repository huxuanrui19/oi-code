#include<bits/stdc++.h>
using namespace std;
int a,n;
const int npos=1004004;
int lucky[int(1.05e6+5)],last[int(1.05e6+5)];
int main()
{
	cin>>a>>n;
	for(int i=ceil(sqrt(a));i<=1002;i++)
	{
		int j=1;
		while(i*i*j<int(1.05e6))
		{
			lucky[i*i*j]=1;
			j++;
		}
	}
	int l=npos;
	for(int i=1.05e6;i>=1;i--)
	{
		if(lucky[i])
		{
			l=i;
		}
		last[i]=l;
	}
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		if(last[x]==x)
		{
			cout<<"lucky";
		}
		else
		{
			cout<<last[x];
		}
		cout<<endl;
	}
	return 0;
}
