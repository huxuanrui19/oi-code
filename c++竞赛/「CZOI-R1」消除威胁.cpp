#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10,M=20;
inline ll cal(ll x){
	return x*(x-1)/2;
}
int n,a[N],b[N],cnt[N],last[N],st[N][M];
void build(){
	for(int i=1;i<=n;i++){
		st[i][0]=a[i];
	}
	int m=log2(n);
	for(int i=1;i<=m;i++){
		for(int j=1;(j+(1<<i)-1)<=n;j++){
			st[j][i]=max(st[j][i-1],st[j+(1<<(i-1))][i-1]);
		}
	}
}
inline int query(int l,int r){
	int p=log2(r-l+1);
	return max(st[l][p],st[r-(1<<p)+1][p]); 
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		a[i]=abs(x);
		b[i]=a[i];
	}
	build();
	sort(b+1,b+n+1);
	int m=unique(b+1,b+n+1)-b-1;
	ll ans=0;
	for(int i=1;i<=n;i++){
		int tmp=lower_bound(b+1,b+m+1,a[i])-b;
		if(cnt[tmp]==0){
			cnt[tmp]++;
			last[tmp]=i;
		}
		else if(query(last[tmp],i)<=a[i]){
			cnt[tmp]++;
		}
		else{
			ll res=cnt[tmp]/2;
			if(a[i]!=0) ans+=cal(res)+cal(cnt[tmp]-res);
			else if(a[i]==0) ans+=cal(cnt[tmp]);
			cnt[tmp]=1;
			last[tmp]=i; 
		}
	}
	for(int i=1;i<=m;i++){
		if(cnt[i]<=1) continue;
		ll res=cnt[i]/2;
		if(b[i]!=0) ans+=cal(res)+cal(cnt[i]-res);
		else if(b[i]==0) ans+=cal(cnt[i]);
	}
	cout<<ans;
	return 0;
}
