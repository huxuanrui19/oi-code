#include<bits/stdc++.h>
using namespace std;
int a[int(1e3+5)];
int main()
{
	int n;
	cin>>n;
	int f,s;
	cin>>f;
	for(int i=1;i<n;i++)
	{
		cin>>s;
		if(abs(f-s)>n-1)
		{
			cout<<"Not jolly";
			return 0;
		}
		else
		{
			a[abs(f-s)]++;
		}
		f=s;
	}
	for(int i=1;i<n;i++)
	{
		if(!a[i])
		{
			cout<<"Not jolly";
			return 0;
		}
	}
	cout<<"Jolly";
	return 0;
}
