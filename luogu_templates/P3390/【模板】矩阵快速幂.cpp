#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100;
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
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,k;
	cin>>n>>k;
	mx a;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>a.m[i][j];
		}
	}
	a=fpmx(a,k);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<a.m[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

