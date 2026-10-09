#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
int n,minn,a[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int ans=-1e9;
	cin>>n; 
	for(int i=1;i<=n;i++) cin>>a[i];
	minn=a[1];
	for(int i=2;i<=n;i++){
		ans=max(ans,a[i]-minn);
		minn=min(minn,a[i]);
	}
	cout<<ans;
	return 0;
}

