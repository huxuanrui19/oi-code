#include<bits/stdc++.h>
using namespace std;
int a[int(5e5+5)],b[int(5e5+5)],flag[int(5e5+5)];
int main()
{
	int m,n;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=m;i++)
	{
		cin>>b[i];
	}
	sort(b+1,b+m+1);
	for(int i=1;i<=n;i++)
	{
		int t=lower_bound(b+1,b+m+1,a[i])-b;
		if(t<=m&&b[t]==a[i])
		{
			flag[i]=1; 
		}
		else
		{
			flag[i]=0;
		}
	}
	int mark=1,cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(mark&&!flag[i])
		{
			cnt++;
			mark=0;
		}
		if(flag[i])
		{
			mark=1;
		}
	}
	cout<<cnt;
	return 0;
}
