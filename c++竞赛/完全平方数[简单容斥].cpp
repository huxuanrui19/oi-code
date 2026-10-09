#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10;
ll cnt=0,pri[N],vis[N],mu[N];
void init(){
	vis[1]=mu[1]=1;
	for(int i=2;i<N;i++){
		if(vis[i]==0){
			pri[++cnt]=i;mu[i]=-1;
		}
		for(int j=1;pri[j]*i<N&&j<=cnt;j++){
			vis[pri[j]*i]=1;
			if(i%pri[j]==0){
				mu[i*pri[j]]=0;
				break;
			}
			mu[i*pri[j]]=-mu[i];
		}
	}
}
ll check(ll n){
	ll ans=0;
	for(ll i=1;i*i<=n;i++) ans+=mu[i]*(n/(i*i));
	return ans; 
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	int t;cin>>t;init();
	while(t--){
		ll n;cin>>n;
		ll l=1,r=1e11,ans=0;
		while(l<r){
			ll mid=(l+r)>>1;
			if(check(mid)>=n) r=mid,ans=r;
			else if(check(mid)<n) l=mid+1;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
