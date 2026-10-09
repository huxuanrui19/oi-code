#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e6+10;
ll mu[N],phi[N],vis[N],pri[N];
unordered_map<ll,ll> sumphi;
unordered_map<ll,ll> summu;
void init()
{
	vis[0]=vis[1]=1;
    mu[1]=phi[1]=1;
    int cnt=0;
    for(int i=2;i<N;i++){
        if(vis[i]==0){
            phi[i]=i-1;
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
                phi[i*pri[j]]=phi[i]*pri[j];
                mu[i*pri[j]]=0;
                break;
            }
            phi[i*pri[j]]=phi[i]*phi[pri[j]];
            mu[i*pri[j]]=-mu[i];
        }
    }
    for(int i=1;i<N;i++){
        phi[i]+=phi[i-1];
        mu[i]+=mu[i-1];
    }
}
ll getsphi(ll x){
	if(x<N){
		return phi[x];
	}
	else if(sumphi[x]){
		return sumphi[x];
	}
	ll ans=x*(x+1)/2;
	for(ll l=2,r;l<=x;l=r+1){
		r=x/(x/l);
		ans-=(r-l+1)*getsphi(x/l);
	}
	sumphi[x]=ans;
	return ans;
}
ll getsmu(ll x){
	if(x<N){
		return mu[x];
	}
	else if(summu[x]){
		return summu[x];
	}
	ll ans=1;
	for(ll l=2,r;l<=x;l=r+1){
		r=x/(x/l);
		ans-=(r-l+1)*getsmu(x/l);
	}
	summu[x]=ans;
	return ans;
}
int main(){
	init();
	int t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		cout<<getsphi(n)<<" "<<getsmu(n)<<endl;
	}
	return 0;
}
