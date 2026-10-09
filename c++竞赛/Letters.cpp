#include<bits/stdc++.h>
using namespace std;
int r,c;
int maxl=-1,x[4]={1,0,-1,0},y[4]={0,1,0,-1};
char a[22][22],visit[26];
void dfs(int i,int j,int len)
{
	visit[a[i][j]-'A']=1;
	maxl=max(maxl,len);
	for(int k=0;k<4;k++)
	{
		int ii=i+x[k];
		int jj=j+y[k];
		if((ii<=r&&ii>0)&&(jj<=c&&jj>0))
		{
			if(!visit[a[ii][jj]-'A'])
			{
				dfs(ii,jj,len+1);
				visit[a[ii][jj]-'A']=0;
			}
		}
	}
	return;
}
int main()
{
	cin>>r>>c;
	for(int i=1;i<=r;i++)
	{
		for(int j=1;j<=c;j++)
		{
			cin>>a[i][j];
		}
	}
	dfs(1,1,1);
	cout<<maxl;
	return 0;
}
