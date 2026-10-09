#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N=5e3+10;
const ld eps=1e-12;
ll n,d,x[N][2],dp[N];
inline ld cal(int i,int j,ld d){return (ld)(x[j][1]-x[i][1]+d)/(x[j][0]-x[i][0]);}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i][0];
		for(int i=1;i<=n;i++) cin>>x[i][1];
		memset(dp,-0x3f,sizeof(dp));
		dp[1]=0;
		for(int i=1;i<=n;i++){
			ld k1=-1e10,k2=1e10;
			for(int j=i+1;j<=n;j++){
				ld k11=cal(i,j,-d),k22=cal(i,j,d),k=cal(i,j,0);
				if(k+eps>=k1&&k-eps<=k2) dp[j]=max(dp[j],dp[i]+(j-i-1));
				k1=max(k1,k11);k2=min(k2,k22);
			}
		}
		cout<<dp[n]<<"\n";
	}
	return 0;
}

