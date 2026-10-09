#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
ll b[N],w[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		w[u]++;
		w[v]++;
	}
	for(int i=1;i<=n;i++){
		b[i]=n-1-w[i];
	}
	ll ans=n*(n-1)*(n-2)/6,cnt=0;
	for(int i=1;i<=n;i++){
		cnt+=w[i]*b[i];
	}
	cout<<ans-cnt/2;
	return 0;
}

