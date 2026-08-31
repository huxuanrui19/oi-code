#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10,M=20;
ll n,k,a[N<<1];
ll LOG2[N<<1],st[N<<1][M];
void build(){
	LOG2[0]=-1;
	for(int i=1;i<=2*n;i++) LOG2[i]=LOG2[i>>1]+1;
	for(int i=1;i<=2*n;i++) st[i][0]=a[i];
	for(int j=1;j<M;j++){
		for(int i=1;i+(1<<j)-1<=2*n;i++){
			st[i][j]=min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
		}
	}
}
inline ll query(int l,int r){
	int p=LOG2[r-l+1];
	return min(st[l][p],st[r-(1<<p)+1][p]);
}
ll check(ll t){
	ll ans=t*k;
	for(int i=n+1;i<=2*n;i++) ans+=query(i-t,i);
	return ans;
}
int main(){
	//freopen("collect3.in","r",stdin);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) a[i+n]=a[i];
	build();
	ll l=0,r=n-1,ans=1e18;
	while(r-l>=10){
		ll lmid=(l*2+r)/3;
		ll rmid=(l+r*2)/3;
		if(check(lmid)<check(rmid)) r=rmid-1;
		else l=lmid+1;
	}
	for(ll i=l;i<=r;i++) ans=min(ans,check(i));
	cout<<ans;
	return 0;
}