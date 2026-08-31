#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10,M=35;
int n,tot,tree[N*M][2];ll ans,a[N];
void insert(int num){
	ll p=0;
	for(int i=30;i>=0;i--){
		int cnt=(num>>i)&1;
		if(tree[p][cnt]==0) tree[p][cnt]=++tot;
		p=tree[p][cnt];
	}
}
ll query(ll num){
	int p=0;ll sum=0;
	for(int i=30;i>=0;i--){
		int cnt=(num>>i)&1;
		if(tree[p][cnt^1]) p=tree[p][cnt^1],sum+=(1<<i);
		else p=tree[p][cnt]; 
	}
	return sum;
}
int main() {
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) insert(a[i]);
	for(int i=1;i<=n;i++) ans=max(ans,query(a[i]));
	cout<<ans;
	return 0;
}
