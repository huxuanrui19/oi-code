#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2; 
ll mod=0;
ll p,q,a1,a2,n;
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
ll kkk(){
	mx a;
	a.m[1][1]=a2;
	a.m[1][2]=a1;
	mx b;
	b.m[1][1]=p;
	b.m[1][2]=1;
	b.m[2][1]=q;
	b.m[2][2]=0;
	b=a*fpmx(b,n-2);
	return b.m[1][1];
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>p>>q>>a1>>a2>>n>>mod;
	if(n==1) cout<<a1;
	else if(n==2) cout<<a2;
	else{
		cout<<kkk();
	}
	return 0;
}

