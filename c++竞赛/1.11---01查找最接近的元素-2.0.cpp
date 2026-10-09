#include<bits/stdc++.h>
using namespace std;
struct node{
	int d,num;
}b[int(1e5+5)];
int a[int(1e5+5)];
bool comp(node x,node y)
{
	if(x.d!=y.d)
	{
		return x.d<y.d;
	}
	else
	{
		return x.num<y.num;
	}
}
int main(){
	int n,m,tar;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	cin>>m;
	for(int i=1;i<=m;i++)
	{	
		cin>>tar;
		int l=1,r=n;
		if(a[1]>=tar)
		{
			cout<<a[1];
		}
		else if(a[n]<=tar)
		{
			cout<<a[n];
		}
		else
		{
			int mid=lower_bound(a+1,a+n+1,tar)-a;
			if(abs(a[mid]-tar)>=abs(a[mid-1]-tar))
			{
				cout<<a[mid-1];
			}
			else
			{
				cout<<a[mid];
			}
		}
		cout<<endl;
	}
	return 0;
}
