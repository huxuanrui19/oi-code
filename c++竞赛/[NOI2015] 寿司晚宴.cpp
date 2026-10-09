#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e2+10,M=300;		//NÖÐ98¸öËØÊý 
ll n,p,ans,g[M][M],w[M][M],dp[M][M],pri[]={2,3,5,7,11,13,17,19};
struct node{
	ll st,mx;
	bool operator <(const node x)const{
		return mx<x.mx;
	}
}a[N];
void pre(){
	for(int i=2;i<=n;i++){
		a[i].mx=a[i].st=0;
		int t=i;
		for(int j=0;j<=7;j++){
			if(t%pri[j]==0){
				a[i].st|=(1<<j);
				while(t%pri[j]==0){
					t/=pri[j];
				}
			}
		}
		if(t>1) a[i].mx=t;
	}
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>p;
	pre();
	sort(a+2,a+n+1);
	g[0][0]=w[0][0]=dp[0][0]=1;
	for(int i=2;i<=n;i++){
		int st=a[i].st;
		for(int j=255;j>=0;j--){
			for(int k=255;k>=0;k--){
				if(j&k) continue;
				if((st&k)==0) g[st|j][k]=(g[st|j][k]+g[j][k])%p;
				if((st&j)==0) w[j][st|k]=(w[j][st|k]+w[j][k])%p;
			}
		}
		if(a[i].mx!=0&&(i+1<=n&&a[i].mx==a[i+1].mx)) continue;
		for(int j=0;j<=255;j++){
			for(int k=0;k<=255;k++){
                if(j&k) continue;
				dp[j][k]=(g[j][k]+w[j][k]-dp[j][k]+p)%p;
			}
		}
		for(int j=0;j<=255;j++){
			for(int k=0;k<=255;k++){
				g[j][k]=w[j][k]=dp[j][k];
			}
		}
	}
	for(int i=0;i<=255;i++){
		for(int j=0;j<=255;j++){
			ans=(ans+dp[i][j])%p;
		}
	}
	cout<<ans;
	return 0;
}

