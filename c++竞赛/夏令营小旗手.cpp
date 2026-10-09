#include<bits/stdc++.h>
using namespace std;
int a[1005];
int main()
{
	int n,x;
	cin>>n>>x;
	int l=x;
	a[l]++;
	for(int i=2;i<=n;i++)
	{
		x=((l*37+33031)%n)+1;
		a[x]++;
		l=x;
	}
	int maxn=-1,k=0;
	for(int i=1;i<=n;i++)
	{
		if(maxn<a[i])
		{
			maxn=a[i];
			k=i;
		}
	}
	cout<<k;
}
