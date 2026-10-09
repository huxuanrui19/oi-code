#include<bits/stdc++.h>
using namespace std;
int d,i,cnt=0,ans=0;
void dfs(int k)
{
	if(k>=pow(2,d))
	{
		cnt++;
		if(cnt==i)
		{
			ans=k/2;
			return;
		}
		return;
	}
	dfs(2*k);
	dfs(2*k+1);
}
int main()
{
	cin>>d>>i;
	dfs(1);
	cout<<ans;
	return 0;
}
