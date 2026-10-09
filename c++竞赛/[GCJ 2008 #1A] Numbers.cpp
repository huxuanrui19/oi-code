#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
const ll mod=1000;
struct maxi{
	int a[3][3];
};
maxi operator *(maxi x,maxi y){
	maxi c;
    memset(c.a,0,sizeof(c.a));
	for(int i=1;i<=2;i++){
		for(int j=1;j<=2;j++){
			for(int k=1;k<=2;k++){
				c.a[i][j]=(c.a[i][j]+x.a[i][k]*y.a[k][j])%mod;
			}
		}
	}
	return c;
} 
maxi fpmx(maxi m,ll c){
	maxi ans;
	ans.a[1][1]=ans.a[2][2]=1;ans.a[1][2]=ans.a[2][1]=0;
	while(c){
		if(c&1) ans=ans*m;
		m=m*m;
		c>>=1;
	}
	return ans;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);cout.tie(NULL);
	int t,num=0;
	cin>>t;
	while(t--){
		num++;
		ll n;cin>>n;
		maxi m;m.a[1][2]=-4;m.a[2][1]=1;m.a[2][2]=6;m.a[1][1]=0;
		m=fpmx(m,n-1);
		ll ans=((2*m.a[1][2]+6*m.a[2][2]-1)%mod+mod)%mod;
		printf("Case #%d: %03lld\n",num,ans);
	}
	return 0;
}
