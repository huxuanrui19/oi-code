#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e4+10;
const ll mod=998244353;
int n,m;
inline ll qp(ll a,ll b){
	ll sum=1;
	while(b){
		if(b&1) sum=sum*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return sum;
}
struct node{
	ll a,w;
	double rat;
	bool operator <(const node &tmp) const{
		if(rat!=tmp.rat) return rat>tmp.rat;
		else return a>tmp.a;
	}
}x[N];
ll dp[6][12],arr[N];
int main(){
	//freopen("sale.in","r",stdin);
	//freopen("sale.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		int flag=1;
		for(int i=1;i<=n;i++){
			cin>>arr[i];
			if(arr[i]!=arr[i-1]&&i!=1) flag=0;
		}
		if(n<=5){
			int ans=0;
			for(int i=0;i<(1<<n);i++){
				for(int j=1;j<=n;j++){
					if(i&(1<<(j-1))) x[j].w=2;
					else x[j].w=1;
					x[j].a=arr[j];
				}
				for(int j=1;j<=n;j++){
					x[j].rat=x[j].a*1.0/x[j].w;
				}
				sort(x+1,x+n+1);
				int tmp=m;
				ll cnt=0;
				for(int j=1;j<=n;j++){
					if(tmp>=x[j].w){
						tmp-=x[j].w;
						cnt+=x[j].a;
					}
				}
				memset(dp,0,sizeof(dp));
				for(int k=1;k<=n;k++){
					for(int j=0;j<=m;j++){
						if(j>=x[k].w) dp[k][j]=max(dp[k][j],dp[k-1][j-x[k].w]+x[k].a);
						dp[k][j]=max(dp[k][j],dp[k-1][j]);
					}
				}
				if(cnt==dp[n][m]){
					ans++;
				}
			}
			cout<<ans<<"\n";
		}
		else if(flag){
			cout<<qp(2,n)<<"\n";
		}
	}
	return 0;
}

