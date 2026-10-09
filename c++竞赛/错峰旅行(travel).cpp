#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10;
const ll mod=1e9+7;
int n,m,s,e;
int cnt=0,sum[N*2],t[N*2];
struct inf{
	int l,r,idx;
}op[N];
ll qp(ll a,ll b){
	ll ans=1;
	while(b){
		if(b&1) ans=ans*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ans;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m>>s>>e;
	for(int i=1;i<=m;i++){
		cin>>op[i].idx>>op[i].l>>op[i].r;
		t[++cnt]=op[i].l;
		t[++cnt]=op[i].r+1;
	}
	sort(t+1,t+cnt+1);
	cnt=unique(t+1,t+cnt+1)-t-1;
	for(int i=1;i<=m;i++){
		int x1=lower_bound(t+1,t+cnt+1,op[i].l)-t;
		int x2=lower_bound(t+1,t+cnt+1,op[i].r+1)-t;
		sum[x1]--;
		sum[x2]++;
	}
	for(int i=1;i<=cnt;i++) sum[i]+=sum[i-1];
	for(int i=1;i<=cnt;i++) sum[i]+=n;
	ll ans=qp(n,t[1]-s)*qp(n,e-t[cnt]+1)%mod;
	for(int i=2;i<=cnt;i++){
		ans=ans*qp(sum[i-1],t[i]-t[i-1])%mod;
	}
	cout<<ans;
	return 0;
}

