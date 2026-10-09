#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5E5+10;
int n,m=0,a[N],tree[N],lis[N];
inline int lowbit(int x){
	return x&(-x);
}
void update(int x){
	while(x<N){
		tree[x]++;
		x+=lowbit(x);
	}
	return;
}
ll query(int x){
	ll ans=0;
	while(x){
		ans+=tree[x];
		x-=lowbit(x);
	}
	return ans;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		lis[i]=a[i];
	}
	sort(lis+1,lis+n+1);
	m=unique(lis+1,lis+n+1)-lis-1;
	ll ans=0;
	for(int i=n;i>=1;i--){
		int x=lower_bound(lis+1,lis+m+1,a[i])-lis;
		ans+=query(x-1);
		update(x);
	}
	cout<<ans;
	return 0;
}
