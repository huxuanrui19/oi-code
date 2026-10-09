#include<bits/stdc++.h>
using namespace std;
int _ffs[105],_ffr[105],_pfs[105],_pfr[105];
int main()
{
	int m,n,r;
	cin>>n>>m>>r;
	for(int i=1;i<=n;i++)
	{
		cin>>_ffs[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>_pfs[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>_ffr[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>_pfr[i];
	}
	int cnt=n;
	for(int i=1;i<=n;i++)
	{
		int tmp;
		cin>>tmp;
		int tf=_ffs[tmp];
		int tp=_pfs[tmp];
		int minn=r+5,k=-1;
		for(int j=1;j<=n;j++)
		{
			if(_ffr[j]==tf&&_pfr[j]>tp)
			{
				if(minn>_pfr[j])
				{
					minn=_pfr[j];
					k=j;
				}
			}
		}
		if(k!=-1)
		{
			_pfr[k]=-1;
			cnt--;
		}
	}
	cout<<cnt;
	return 0;
}
