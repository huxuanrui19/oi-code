#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[105][50005];
int main()
{
	ll n,m,res=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		ll ai;
		cin>>ai;
		a[i][0]=ai;
		ll maxn=-1,minn=1e9+10;
		for(int j=1;j<=ai;j++)
		{
			cin>>a[i][j];
			maxn=max(maxn,a[i][j]);
			minn=min(minn,a[i][j]);
		}
		res+=maxn-minn+1;
	}
	cout<<res;
	return 0;
}
