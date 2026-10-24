#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e6+10;
ll n,p,k,a[N],pre[N],invp[N];
void read(ll &x){
	x=0;ll f=1;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f*=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=(x<<1)+(x<<3)+(ch&15);
		ch=getchar();
	}
    x=x*f;
}
inline ll qp(ll a,ll b){
	ll sum=1;
	while(b){
		if(b&1) sum=sum*a%p;
		a=a*a%p;b>>=1;
	}
	return sum;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
    read(n);read(p);read(k);
	for(int i=1;i<=n;i++) read(a[i]);
	pre[0]=1;
	for(int i=1;i<=n;i++) pre[i]=(pre[i-1]*a[i])%p;
	ll in=qp(pre[n],p-2),ans=0;invp[n]=in;
	for(int i=n-1;i>=1;i--) invp[i]=invp[i+1]*a[i+1]%p;
	invp[0]=1;ll mi=k;
	for(int i=1;i<=n;i++) ans=(ans+(invp[i]*pre[i-1]%p)*mi%p)%p,mi=mi*k%p;
	cout<<ans; 
	return 0;
}

