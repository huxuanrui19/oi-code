#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
ll cnt=0,a[N],lis[N],idx[N],sum[N];
int main(){
	freopen("put.in","r",stdin);
	freopen("put.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	ll n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		lis[i]=a[i];
	}
	sort(lis+1,lis+n+1);
	cnt=unique(lis+1,lis+n+1)-lis-1;
	for(int i=1;i<=n;i++){
		int tmp=lower_bound(lis+1,lis+cnt+1,a[i])-lis;
		idx[tmp]++;
	}
	sort(idx+1,idx+cnt+1);
	for(int i=1;i<=cnt;i++){
		sum[i]=sum[i-1]+idx[i];
	}
	ll ans=1e9+10;
	for(int i=1;i<=cnt;i++){
		ll nxt=upper_bound(idx+1,idx+cnt+1,idx[i]+m)-idx-1;
        ll res=sum[nxt]-sum[i-1]+(idx[i]+m)*(cnt-nxt);
		ans=min(ans,n-res);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

