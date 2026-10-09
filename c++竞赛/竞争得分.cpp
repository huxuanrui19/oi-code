#include<bits/stdc++.h>
using namespace std;
double minn=1005.0,maxn=-1.0,a[1005];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		minn=min(minn,a[i]);
		maxn=max(maxn,a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		int tmp=int(100.0*(a[i]-minn)/(maxn-minn));
		cout<<tmp<<" ";
	}
	return 0;
}
