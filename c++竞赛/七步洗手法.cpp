#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
ll a[N],b[N]; 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		a[i]=n-1;
	}
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		a[u]--;
		b[u]++;
		a[v]--;
		b[v]++;
	}
	ll ans=n*(n-1)*(n-2)/6,cnt=0;
	for(int i=1;i<=n;i++){
		cnt+=a[i]*b[i];
	}
	ans-=cnt/2;
	cout<<ans;
	return 0;
}

