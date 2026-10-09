#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+5;
vector<int> g[N];
/*void bfs(int d)
{
	for(auto:g[d])
	{
		bfs(d);
	}
}*/
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		for(int i=1;i<=m;i++)
		{
			int a,b,c;
			cin>>a>>b>>c;
			g[a].push_back(b);
			g[b].push_back(a);
		}
		if(m==0)
		{
			cout<<"Yes"<<endl;
		}
		else
		{
			for(int i=1;i<=n;i++)
		}
	}
	return 0;
}
