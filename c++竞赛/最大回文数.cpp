#include<bits/stdc++.h>
using namespace std;
int comp(string s,string maxs)
{
	if(s.size()!=maxs.size())
	{
		return s.size()>maxs.size();
	}
	else
	{
		for(int i=0;i<s.size();i++)
		{
			if(s[i]!=maxs[i])
			{
				return s[i]>maxs[i];
			}
		}
	}
	return 0;
}
int main()
{
	int n;
	cin>>n;
	string s,maxs="0";
	for(int i=1;i<=n;i++)
	{
		cin>>s;
		int flag=1;
		for(int l=0,r=s.size()-1;l<=r;l++,r--)
		{
			if(s[l]!=s[r])
			{
				flag=0;
				break;
			}
		}
		if(flag)
		{
			if(comp(s,maxs))
			{
				maxs=s;
			}
		}
	}
	cout<<maxs;
	return 0;
}
