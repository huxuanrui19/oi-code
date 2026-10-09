#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10;
ll cnt,vis[N],pri[N],mu[N],sum[N];
void init(){
	vis[1]=mu[1]=1;
	for(int i=2;i<N;i++){
		if(vis[i]==0){
			pri[++cnt]=i;
			mu[i]=-1;
			vis[i]=0;
		}
		for(int j=1;j<=cnt;j++){
			if(i*pri[j]>=N){
				break;
			}
			vis[i*pri[j]]=1;
			if(i%pri[j]==0){
				mu[i*pri[j]]=0;
				break;
			}
			mu[i*pri[j]]=-mu[i];
		}
	}
	sum[1]=1;
	for(int i=2;i<N;i++){
		sum[i]=sum[i-1]+mu[i];
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,m,d;
	cin>>n>>m>>d;
	ll ans=0;
	init();
	if(n>m) swap(n,m);
	n/=d;m/=d;
	for(ll l=1,r;l<=n;l=r+1){
		r=min(n/(n/l),m/(m/l));
		ans+=(sum[r]-sum[l-1])*(n/l)*(m/l);
	}
	cout<<ans;
	return 0;
}

