#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=4e3+10,M=1e4+10;
const ll mod=998244353;
ll fac[M],inv[M];
inline ll qp(ll n,ll k){
	ll sum=1;
	while(k){
		if(k&1) sum=sum*n%mod;
		k>>=1;n=n*n%mod;
	}
	return sum;
}
void init(){
	fac[0]=1;for(int i=1;i<M;i++) fac[i]=fac[i-1]*i%mod;
	inv[M-1]=qp(fac[M-1],mod-2);for(int i=M-2;i>=0;i--) inv[i]=inv[i+1]*(i+1)%mod;
}
inline ll C(ll n,ll m){return fac[n]*inv[m]%mod*inv[n-m]%mod;}
ll n,m,k,dp1[N][N],dp2[N][N],a[N][N],col[N],row[N]; 
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m>>k;
	init();
	for(int i=1;i<=k;i++){
		ll x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		a[x1][y1]++;
		a[x2][y2]++;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			row[i]+=a[i][j];
		}
	}
	for(int j=1;j<=m;j++){
		for(int i=1;i<=n;i++){
			col[j]+=a[i][j];
		}
	}
	ll r=n,c=m;
	for(int i=1;i<=n;i++) r-=(row[i]!=0);
	for(int j=1;j<=m;j++) c-=(col[j]!=0);
	dp1[0][0]=1;row[0]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=n;j++){
			dp1[i][j]=dp1[i-1][j];
			if(j&&(!(row[i]||row[i-1]))) dp1[i][j]=(dp1[i][j]+dp1[i-2][j-1])%mod;
		}
	}
	dp2[0][0]=1;col[0]=1;
	for(int i=1;i<=m;i++){
		for(int j=0;j<=m;j++){
			dp2[i][j]=dp2[i-1][j];
			if(j&&(!(col[i]||col[i-1]))) dp2[i][j]=(dp2[i][j]+dp2[i-2][j-1])%mod;
		}
	}
	ll ans=0;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			if(i+2*j<=r&&i*2+j<=c){
				ans+=C(r-2*j,i)*C(c-2*i,j)%mod*dp1[n][j]%mod*dp2[m][i]%mod*fac[i]%mod*fac[j]%mod;
				ans%=mod;
			}
		}
	}
	cout<<ans;
	return 0;
}

