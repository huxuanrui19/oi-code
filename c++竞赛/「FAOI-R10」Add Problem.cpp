#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=4e5+10;
int n,m,maxn,a[N];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	for(int i=1;i<=n;i++){
		a[i]=maxn-a[i];
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		ans=max(ans,(int)ceil((double)a[i]/m));
	}
	cout<<ans;
	return 0;
}

