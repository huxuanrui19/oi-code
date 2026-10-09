#include<bits/stdc++.h>
using namespace std;
int a[int(1e5+5)];
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
			//int mid=lower_bound(a+1,a+n+1,tar)-a;
			int mid,pos;
			while(l<=r)
			{
				mid=(l+r)/2;
				if(a[mid]>=tar)
				{
					pos=mid;
					r=mid-1;
				}
				else
				{
					l=mid+1;
				}
			}
			if(a[pos]==tar)
			{
				cout<<tar;
			}
			else if(abs(a[pos]-tar)<abs(a[pos-1]-tar))
			{
				cout<<a[pos];
			}
			else
			{
				cout<<a[pos-1];
			}
		}
		cout<<endl;
	}
	return 0;
}
