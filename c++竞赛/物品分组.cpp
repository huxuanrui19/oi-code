#include<bits/stdc++.h>
using namespace std;
int n,m,l=0,r=0,mid,ans;
int a[int(1e5+5)];
int check(int x)
{
	int sum=0,cnt=1;
	for(int i=1;i<=n;i++)
	{
		if(sum+a[i]<=x)
		{
			sum+=a[i];
		}
		else
		{
			sum=a[i];
			cnt++;
		}
	}
	return cnt<=m;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		l=max(l,a[i]);
		r+=a[i];
	}
	cin>>m; 
	while(l<=r)
	{
		mid=(l+r)/2;
		if(check(mid))
		{
			ans=mid;
			r=mid-1; 
		}
		else
		{
			l=mid+1;
		}
	}
	cout<<ans;
	return 0;
}
