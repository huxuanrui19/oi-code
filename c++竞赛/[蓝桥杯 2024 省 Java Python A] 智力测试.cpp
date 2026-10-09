#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
const ll mod=1e9+7; 
ll n,m,t,cntn,cntm,r[N],c[N],rls[N],cls[N],fac[N],facinv[N],rprod[N],cprod[N],rtot[N],ctot[N];
ll qp(ll a,ll n){
	ll sum=1;
	while(n){
		if(n&1) sum=sum*a%mod;
		a=a*a%mod;
		n>>=1;
	}
	return sum;
}
ll inv(ll n){
	return qp(n,mod-2);
}
void init(){
	fac[0]=facinv[0]=1;
	for(int i=1;i<N;i++){
		fac[i]=fac[i-1]*i%mod;
		facinv[i]=inv(fac[i]);
	}
}
ll C(ll n,ll m){
	if(m>n) return 0;
	return (fac[n]*facinv[m]%mod)*facinv[n-m]%mod;
}
void solve(){
	rprod[0]=cprod[0]=1;
	for(int i=1;i<=n;i++){
		int tmp=lower_bound(rls+1,rls+cntn+1,r[i])-rls;
		rprod[tmp]++;
		rtot[tmp]++;
	}
	for(int i=1;i<=cntn;i++){
		rprod[i]=rprod[i]*rprod[i-1]%mod;
		rtot[i]+=rtot[i-1];
	}
	for(int i=1;i<=m;i++){
		int tmp=lower_bound(cls+1,cls+cntm+1,c[i])-cls;
		cprod[tmp]++;
		ctot[tmp]++;
	}
	for(int i=1;i<=cntm;i++){
		cprod[i]=cprod[i]*cprod[i-1]%mod;
		ctot[i]+=ctot[i-1];
	}
}
ll ask(ll u,ll v,ll x,ll y){
	ll lsu=lower_bound(rls+1,rls+cntn+1,r[u])-rls;
	ll lsv=lower_bound(cls+1,cls+cntm+1,c[v])-cls;
	ll lsx=lower_bound(rls+1,rls+cntn+1,r[x])-rls;
	ll lsy=lower_bound(cls+1,cls+cntm+1,c[y])-cls;
	if((lsu>=lsx&&u!=x)||(lsv>=lsy&&v!=y)) return 0;
	ll row=rtot[lsx-1]-rtot[lsu]+1;
	ll col=ctot[lsy-1]-ctot[lsv]+1;
	ll ans=C(row+col,row);
	ll resr=rprod[lsx-1]*inv(rprod[lsu])%mod;
	ll resc=cprod[lsy-1]*inv(cprod[lsv])%mod;
	if(u==x&&v==y) return 1;
	if(u!=x) ans=ans*resr%mod;
	if(v!=y) ans=ans*resc%mod;
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m>>t;
	for(int i=1;i<=n;i++){
		cin>>r[i];
		rls[i]=r[i];
	}
	for(int i=1;i<=m;i++){
		cin>>c[i];
		cls[i]=c[i];
	}
	init();
	sort(rls+1,rls+n+1);
	sort(cls+1,cls+m+1);
	cntn=unique(rls+1,rls+n+1)-rls-1;
	cntm=unique(cls+1,cls+m+1)-cls-1;
	solve();
	while(t--){
		ll u,v,x,y;
		cin>>u>>v>>x>>y;
		cout<<ask(u,v,x,y)<<"\n";
	}
	return 0;
}

