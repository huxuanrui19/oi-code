#include<bits/stdc++.h>
using namespace std;
int ans=0,b[9],c[17],d[17],q[9],s[93][9];
void dfs(int i)
{
	if(i>8)
	{
		++ans;
		for(int j=1;j<=8;j++)
		{
			s[ans][j]=q[j];
		}
		return;
	}
	else
	{
		for(int j=1;j<=8;j++)
		{
			if(b[j]==0&&c[i-j+8]==0&&d[i+j]==0)
			{
				q[i]=j;
				b[j]=1;
				c[i-j+8]=1;
				d[i+j]=1;
				dfs(i+1);
				b[j]=0;
				c[i-j+8]=0;
				d[i+j]=0;
			}
		}
		return;
	}
}
int main()
{
	int n;
	cin>>n;
	dfs(1);
	while(n--)
	{
		int tmp;
		cin>>tmp;
		for(int i=1;i<=8;i++)
		{
			cout<<s[tmp][i];
		}
		cout<<endl;
	}
	return 0;
}
