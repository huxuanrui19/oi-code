#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e2+10,M=256;
ll n,p,f[M][M],g[M][M],dp[M][M],pri[8]={2,3,5,7,11,13,17,19};
struct node{
	int st,mx;
	bool operator <(const node &tmp)const{
		return mx<tmp.mx;
	}
}a[N];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n>>p;
	for(int i=2;i<=n;i++){
		int x=i,st=0;
		for(int j=0;j<8;j++){
			if(x%pri[j]==0){
				st|=(1<<j);
				while(x%pri[j]==0){
					x/=pri[j];
				}
			}
		}
		a[i].st=st;a[i].mx=(x==1?0:x);
	}
	sort(a+2,a+n+1);
	f[0][0]=g[0][0]=dp[0][0]=1;
	for(int i=2;i<=n;i++){
		int st=a[i].st;
		for(int j=M-1;j>=0;j--){
			for(int k=M-1;k>=0;k--){
				if(j&k) continue;
				if((st&k)==0) f[st|j][k]=(f[st|j][k]+f[j][k])%p;
				if((st&j)==0) g[j][st|k]=(g[j][st|k]+g[j][k])%p;
			}
		}
		if(a[i].mx!=0&&i+1<=n&&a[i+1].mx==a[i].mx) continue;
		for(int j=0;j<M;j++){
			for(int k=0;k<M;k++){
				if(j&k) continue;
				dp[j][k]=((f[j][k]+g[j][k]-dp[j][k])%p+p)%p;
			}
		}
		for(int j=0;j<M;j++){
			for(int k=0;k<M;k++){
				f[j][k]=g[j][k]=dp[j][k];
			}
		}
	}
	ll ans=0;
	for(int j=0;j<M;j++){
		for(int k=0;k<M;k++){
			ans=(ans+dp[j][k])%p;
		}
	}
	cout<<ans;
	return 0;
}

