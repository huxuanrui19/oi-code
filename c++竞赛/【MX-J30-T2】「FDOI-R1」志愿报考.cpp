#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
ll n,s,t,y,lt,rt,lmin,rmax,x,a[N],cnt[N];
ll cal(ll l,ll r){
	if(l>r) return 0;
	ll ans=0;
	if(l<=lt){
		ans+=max(l-lmin,0ll)*max(0ll,min(lt,r)-l+1)+max(0ll,min(lt,r)-l+1)*max(0ll,min(lt,r)-l+2)/2;
		l=lt+1;		//矩形+三角形 
	}
	if(r>=rt){
		ans+=max(0ll,r-max(rt,l)+1)*max(0ll,r-max(rt,l)+2)/2;	//项数*（首项+末项（1）） 
		r=rt-1;
	}
	ans+=max(0ll,(r-l+1)*x);	//矩形 
	return ans;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n>>s>>t>>y;
	lt=min(s+y,t-y);
	rt=max(s+y,t-y);
	lmin=s-y;rmax=t+y;
	x=min(t-s+1,y*2+1);
	for(int i=1;i<=n;i++) cin>>a[i];
	ll maxn=cal(max(lmin,a[1]),rmax),idx=1;
	for(int i=2;i<=n;i++){
		
		ll cnt=cal(max(lmin,a[i]),rmax);
		if(cnt>maxn||(cnt==maxn&&a[idx]>a[i])) idx=i,maxn=cnt;
		rmax=min(rmax,a[i]-1);
	}
	ll cnt=cal(lmin,rmax);
	if(cnt>=maxn) idx=0,maxn=cnt;
	if(idx==0) cout<<0;
	else cout<<a[idx];
	return 0;
}

