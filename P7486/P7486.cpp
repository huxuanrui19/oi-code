#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10;
const ll mod=32465177;
ll t,n;
template < typename T >
void read(T &x){
	x=0;int f=1;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f*=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=(x<<1)+(x<<3)+(ch&15);
		ch=getchar(); 
	}
	x*=f;
}
void write(int x)
{
    if(x<0)
        putchar('-'),x=-x;
    if(x>9)
        write(x/10);
    putchar(x%10+'0');
    return;
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
ll cnt,mu[N],vis[N],pri[N],f[N],finv[N],fprod[N],sum[N],x1[N],x2[N],g[N],ginv[N],sumx1[N];
inline void pre(){
	mu[1]=1;
	vis[1]=1;
	for(int i=2;i<=n;i++){
		if(!vis[i]){
			mu[i]=-1;
			pri[++cnt]=i;
		}
		for(int j=1;j<=cnt&&i*pri[j]<=n;j++){
			vis[i*pri[j]]=1;
			if(i%pri[j]==0){
				mu[i*pri[j]]=0;
				break;
			}
			mu[i*pri[j]]=-mu[i];
		}
	}
	
	fprod[0]=1;
	for(int i=1;i<=n;i++){
		f[i]=qp(i,i);
		finv[i]=qp(f[i],mod-2);
		fprod[i]=fprod[i-1]*f[i]%mod;
		sum[i]=1ll*i*(i+1)/2;
		x2[i]=1;
	} 
	for(ll i=1;i<=n;i++){
		for(ll j=1;j*i<=n;j++){
			x1[i*j]=((x1[i*j]+i*mu[i])%(mod-1)+mod-1)%(mod-1);
			if(mu[i]>0){
				x2[i*j]=x2[i*j]*f[i]%mod;
			}
			else if(mu[i]<0){
				x2[i*j]=x2[i*j]*finv[i]%mod;
			}
		}
	}
	g[0]=ginv[0]=1;
	for(int i=1;i<=n;i++){
		sumx1[i]=(sumx1[i-1]+i*x1[i])%(mod-1);
		g[i]=g[i-1]*qp(qp(i,x1[i])*x2[i]%mod,i)%mod;
		ginv[i]=qp(g[i],mod-2);
	}
}
inline ll yy(ll n,ll m){
	return qp(fprod[n],sum[m]%(mod-1))*qp(fprod[m],sum[n]%(mod-1))%mod;
}
inline ll s(ll n,ll m){
	ll ans=1;
	if(n>=m) swap(n,m);
	for(ll l=1,r;l<=n;l=r+1){
		r=min(n/(n/l),m/(m/l));
		ans=ans*(qp(yy(n/l,m/l),((sumx1[r]-sumx1[l-1])%(mod-1)+mod-1)%(mod-1))*qp(g[r]*ginv[l-1]%mod,(__int128)sum[n/l]*sum[m/l]%(mod-1))%mod)%mod;
	}
	return ans;
}
inline ll solve(ll l,ll r){
	ll ans1=s(r,r);
	ll ans2=s(l-1,l-1);
	ll ans3=s(l-1,r);
	return (ans1*ans2%mod)*qp(ans3,2*(mod-2))%mod;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	read(t);read(n);
	pre(); 
	while(t--){
		int l,r;
		read(l);read(r);
		write(solve(l,r));
		putchar('\n');
	}
	return 0;
}