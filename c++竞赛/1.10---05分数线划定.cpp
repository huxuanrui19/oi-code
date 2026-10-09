#include<bits/stdc++.h>
using namespace std;
struct node{
	int k,s;
}a[5005];
bool comp(node x,node y)
{
	if(x.s<y.s)
	{
		return 0;
	}
	else if(x.s>y.s)
	{
		return 1;
	}
	else
	{
		if(x.k>y.k)
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
}
int main()
{
	int n,m;
	cin>>n>>m;
	int res=floor(m*1.5);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].k>>a[i].s;
	}
	sort(a+1,a+n+1,comp);
	int sc=a[res].s;
	while(a[res+1].s==sc)
	{
		res++;
	}
	cout<<sc<<" "<<res<<endl;
	for(int i=1;i<=res;i++)
	{
		cout<<a[i].k<<" "<<a[i].s<<endl;
	}
	return 0;
}
