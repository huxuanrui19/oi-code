#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+10;
ll cnt,pri[N],vis[N],phi[N],sum[N];
void init(){
	vis[1]=phi[1]=1;
	for(int i=2;i<N;i++){
		if(!vis[i]){
			phi[i]=i-1;
			vis[i]=1;
			pri[++cnt]=i;
		}
		for(int j=1;j<N;j++){
			if(i*pri[j]>=N){
				break;
			}
			vis[i*pri[j]]=1;
			if(i%pri[j]==0){
				phi[i*pri[j]]=phi[i]*pri[j];
				break;
			}
			phi[i*pri[j]]=phi[i]*(phi[pri[j]]);
		}
	}
	for(int i=1;i<N;i++){
		sum[i]=sum[i-1]+phi[i];
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
	ll n,ans=0;
	cin>>n;
	for(ll l=1,r;l<=n;l=r+1){
		r=n/(n/l);
		ans+=(sum[r]-sum[l-1])*(n/l)*(n/l);
	}
	cout<<(ans-n*(n+1)/2)/2;
	return 0;
}

