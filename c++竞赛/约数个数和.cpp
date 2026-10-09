#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e4+10;
ll cnt,mu[N],vis[N],pri[N],sum[N],tot[N];
void init()
{
    mu[1]=1;
    for(int i=2;i<N;i++){
        if(vis[i]==0){
            mu[i]=-1;
            vis[i]=1;
            pri[++cnt]=i;
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
            mu[i*pri[j]]=mu[i]*mu[pri[j]];
        }
    }
    sum[1]=mu[1];
    for(int i=2;i<N;i++){
    	sum[i]=sum[i-1]+mu[i];
	}
}
void cal(){
	for(int i=1;i<N;i++){
		for(int l=1,r;l<=i;l=r+1){
			r=i/(i/l);
			tot[i]+=1ll*(r-l+1)*(i/l);
		}
	}
}
ll kkk(ll n,ll m){
	ll ans=0;
	if(n>m) swap(n,m);
	for(ll l=1,r;l<=n;l=r+1){
		r=min(n/(n/l),m/(m/l));
		ans+=(sum[r]-sum[l-1])*tot[n/l]*tot[m/l];
	}
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	init();
	cal();
	while(t--){
		ll n,m;
		cin>>n>>m;
		cout<<kkk(n,m)<<'\n';
	}
	return 0;
}

