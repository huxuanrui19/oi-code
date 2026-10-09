#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
const ll mod=1e9+7;
ll n,m,k;
struct node{
	int xi,yi;
}a[N];
ll x[N],y[N],xsum[N],ysum[N];
ll qp(ll a,ll b){
	ll sum=1;
	while(b){
		if(b&1) sum=sum*a%mod;
		b>>=1;a=a*a%mod;
	}
	return sum;
}
ll inv2,inv6;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m>>k;inv2=qp(2,mod-2);inv6=qp(6,mod-2);
	for(int i=1;i<=k;i++){
		cin>>a[i].xi>>a[i].yi;
		x[i]=a[i].xi;y[i]=a[i].yi;
	}
	ll ans=0,xans=0,yans=0;
	xans=(((n*n+n)%mod*n%mod-n*(n+1)%mod*(2*n+1)%mod*inv6%mod+n*(n+1)%mod*inv2%mod)%mod+mod)%mod*inv2%mod;
	xans=((xans-(n+1)*n%mod*(n+1)%mod*inv2%mod+n*(n+1)%mod*(2*n+1)%mod*inv6%mod)%mod+mod)%mod;
	xans=((xans+n*(n+1)%mod*(2*n+1)%mod*inv6%mod*inv2-n*(n+1)%mod*inv2%mod*inv2%mod)%mod+mod)%mod;
	yans=(((m*m+m)%mod*m%mod-m*(m+1)%mod*(2*m+1)%mod*inv6%mod+m*(m+1)%mod*inv2%mod)%mod+mod)%mod*inv2%mod;
	yans=((yans-(m+1)*m%mod*(m+1)%mod*inv2%mod+m*(m+1)%mod*(2*m+1)%mod*inv6%mod)%mod+mod)%mod;
	yans=((yans+m*(m+1)%mod*(2*m+1)%mod*inv6%mod*inv2-m*(m+1)%mod*inv2%mod*inv2%mod)%mod+mod)%mod;
	ans=(xans*m%mod*m+yans*n%mod*n)%mod;
	ll ans1=0;
	for(int i=1;i<=k;i++){
		ll ans1x=0,ans1y=0;
		ans1x=((x[i]*x[i]%mod-x[i]*(x[i]+1)%mod*inv2%mod-(n-x[i]+1)*x[i]%mod+(n+x[i])*(n-x[i]+1)%mod*inv2%mod)%mod+mod)%mod;
		ans1y=((y[i]*y[i]%mod-y[i]*(y[i]+1)%mod*inv2%mod-(m-y[i]+1)*y[i]%mod+(m+y[i])*(m-y[i]+1)%mod*inv2%mod)%mod+mod)%mod;
		ans1=(ans1+(ans1x*m+ans1y*n)%mod)%mod;
	}
	sort(x+1,x+k+1);sort(y+1,y+k+1);
	for(int i=1;i<=k;i++){
		xsum[i]=xsum[i-1]+x[i];
		xsum[i]%=mod;
	}
	for(int i=1;i<=k;i++){
		ysum[i]=ysum[i-1]+y[i];
		ysum[i]%=mod;
	}
	ll ans2=0,ans2x=0,ans2y=0;
	for(int i=1;i<=k;i++){
		ans2x=ans2x+((x[i]*i%mod-xsum[i]+xsum[k]-xsum[i]-x[i]*(k-i)%mod)%mod+mod)%mod;
		ans2y=ans2y+((y[i]*i%mod-ysum[i]+ysum[k]-ysum[i]-y[i]*(k-i)%mod)%mod+mod)%mod;
	}
	ans2=(ans2x+ans2y)%mod;
	ll res=ans-ans1*2+ans2;
	res=(res%mod+mod)%mod;
	//cout<<ans1<<" "<<ans2<<" "<<ans<<"\n";
	cout<<(res*inv2%mod);
	return 0;
}

