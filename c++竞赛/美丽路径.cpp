#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int c[N],dp[N],flag[N],m1[N],m2[N];
vector<int> g[N];
int dfs(int s,int f)
{
	int cur=0;
	flag[s]=true;
	for(vector<int>::size_type d=0;d<g[s].size();d++)
	{
		if(g[s][d]!=f&&c[g[s][d]]!=c[s])
		{
			cur=dfs(g[s][d],s);
			if(cur>m1[s])
			{
				m2[s]=m1[s];
				m1[s]=cur;
			}
			else if(cur>m2[s])
			{
				m2[s]=cur;
			}
		}
	}
	/*for(int d=0;d<g[s].size();d++)
	{
		if(g[s][d]!=f&&c[g[s][d]]!=c[s])
		{
			cur=dfs(g[s][d],s);
			if(cur>m1[s])
			{
				m2[s]=m1[s];
				m1[s]=cur;
			}
			else if(cur>m2[s])
			{
				m2[s]=cur;
			}
		}
	}*/
	/*auto it=g[s].begin();
	for(it;it<g[s].end();it++)
	{
		if(*it!=f&&c[*it]!=c[s])
		{
			cur=dfs(*it,s);
			if(cur>m1[s])
			{
				m2[s]=m1[s];
				m1[s]=cur;
			}
			else if(cur>m2[s])
			{
				m2[s]=cur;
			}
		}
	}*/
	return m1[s]+1;
}
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	for(int i=1;i<n;i++)
	{
		int s,e;
		cin>>s>>e;
		g[s].push_back(e);
		g[e].push_back(s);
	}
	int maxn=-1;
	for(int i=1;i<=n;i++)
	{
		if(!flag[i])
		{
			dfs(i,0);
		}
	}
	for(int i=1;i<=n;i++)
	{
		maxn=max(maxn,m1[i]+m2[i]+1);
	}
	cout<<maxn;
	return 0;
}
