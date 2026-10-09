#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10;
const ll mod=104857601;
int cnt,phi[N],pri[N];
bool vis[N];
void sieve(){
	phi[1]=1;vis[1]=1;
	for(int i=2;i<N;i++){
		if(!vis[i]){
			phi[i]=i-1;
			pri[++cnt]=i;
		}
		for(int j=1;j<=cnt&&i*pri[j]<N;j++){
			vis[i*pri[j]]=1;
			if(i%pri[j]==0){
				phi[i*pri[j]]=phi[i]*pri[j];
				break; 
			}
			phi[i*pri[j]]=phi[i]*(pri[j]-1);
		}
	}
	for(int i=1;i<N;i++){
		phi[i]=(phi[i]+phi[i-1])%(mod-1);
	}
}
inline ll qp(ll a,ll b){
	ll sum=1;
	while(b){
		if(b&1) sum=sum*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return sum;
} 
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	sieve();
	ll n;
	cin>>n;
	ll ans1=1,ans2=1;
	for(int i=1;i<=n;i++){
		ans1=ans1*i%mod;
		ans2=ans2*qp(i,phi[n/i]*2-1)%mod;
	}
	cout<<(qp(ans1,2*n)*qp(ans2,(mod-2)*2)%mod);
	return 0;
}
