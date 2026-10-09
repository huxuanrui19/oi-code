#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2;
const ll mod=1e9+7;
struct mx{
	ll m[N+1][N+1];
};
mx operator * (const mx& a,const mx& b){
	mx c;
	memset(c.m,0,sizeof(c.m));
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			for(int k=1;k<=N;k++){
				c.m[i][j]=(c.m[i][j]+(a.m[i][k]*b.m[k][j])%mod)%mod;
			}
		}
	}
	return c;
}
mx fpmx(mx a,ll b){
	mx ans;
	memset(ans.m,0,sizeof(ans.m));
	for(int i=1;i<=N;i++) ans.m[i][i]=1;
	while(b){
		if(b&1) ans=ans*a;
		a=a*a;
		b>>=1;
	}
	return ans;
}
ll cal(ll n){
	if(n<=2){
		return 1;
	}
	mx a;
	a.m[1][1]=a.m[1][2]=a.m[2][1]=1;
	a.m[2][2]=0;
	a=fpmx(a,n);
	return a.m[2][1];
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n;
	cin>>n;
	cout<<cal(n);
	return 0;
}

