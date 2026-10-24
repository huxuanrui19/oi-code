#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128 lll;
const int N=1e5+10;
ll n,a[11],b[11];
lll tot=1,ans=0,m[11];
lll exgcd(lll a,lll b,lll &x,lll &y){
	if(!b){
		x=1,y=0;
		return a;
	}
	lll d=exgcd(b,a%b,y,x);
	y=y-(a/b)*x;
	return d;
}
lll getinv(lll a,lll mod){
	lll x,y;
	exgcd(a,mod,x,y);
	return (x%mod+mod)%mod;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>b[i];
	for(int i=1;i<=n;i++) tot*=a[i];
	for(int i=1;i<=n;i++) m[i]=tot/a[i];
	for(int i=1;i<=n;i++) ans=(ans+(lll)b[i]*m[i]%tot*getinv(m[i],a[i])%tot)%tot;
	cout<<(ll)(ans%tot);
	return 0;
}

