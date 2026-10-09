#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=20;
ll m=1,a[N],b[N];
ll exgcd(ll a,ll b,__int128 &x,__int128 &y){
	if(b==0){
		x=1;
		y=0;
		return a;
	}
	ll d=exgcd(b,a%b,y,x);
	y-=a/b*x;
	return d;
}
ll qp(ll k,ll n,ll INS)
{
	ll sum=1;
	while(n>0)
	{
		if(n&1)
		{
			sum=sum*k%INS;
		}
		k=k*k%INS;
		n>>=1;
	}
	return sum;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		m*=a[i];
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		__int128 inv,y;
		exgcd(m/a[i],a[i],inv,y);
		ans=(ans+(m/a[i])*inv%m*b[i])%m; 
	}
	cout<<(ans+m)%m;
	return 0;
}

