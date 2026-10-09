#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 998244353;
int n,x,y,z;
int dp[42][1<<18];
int main(){
	cin>>n>>x>>y>>z;
	dp[0][0]=1;
	int t=(1<<(x+y+z)-1)|(1<<y+z-1)|(1<<z-1);
	ll ans=1;
	for(int i=1;i<=n;i++){
		ans=(1ll*10*ans)%mod;
		for(int j=0;j<1<<(x+y+z);j++){
			if(dp[i-1][j]==0)continue;
			for(int k=1;k<=10;k++){
				int s=(j<<k)|(1<<k-1);
				s&=(1<<(x+y+z))-1;
				if((s&t)!=t){
					dp[i][s]=(dp[i][s]+dp[i-1][j])%mod;
				}
			}
		}
	}
	for(int i=0;i<1<<(x+y+z);i++){
		ans=(ans+mod-dp[n][i])%mod;
	}
	cout<<ans;
	return 0;
}
