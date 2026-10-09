#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10,M=20;
const ll mod=998244353;
struct oper{
	int val1,val2;
}a[N];
int n,st[N][M],LOG2[N],dp[N];
void build(){
	LOG2[0]=-1;
	for(int i=1;i<N;i++) LOG2[i]=LOG2[i>>1]+1;
	int p=LOG2[n];
	for(int i=1;i<=n;i++){
		st[i][0]=max(a[i].val1,a[i].val2);
	}
	for(int i=1;i<=p;i++){
		for(int j=1;j+(1<<i)-1<=n;j++){
			st[j][i]=max(st[j][i-1],st[j+(1<<(i-1))][i-1]);
		}
	}
}
inline ll query(int l,int r){
	int p=LOG2[r-l+1];
	return max(st[l][p],st[r-(1<<p)+1][p]);
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	int tmp1,tmp2;
	while(cin>>tmp1>>tmp2){
		a[++n]={tmp1,tmp2};
	}
	/*for(int i=1;i<=n;i++){
		cout<<a[i].val1<<" "<<a[i].val2<<"\n"; 
	}*/
	//cout<<n;
	build();
	//memset(dp,-1,sizeof(dp));
	dp[n+1]=1;
	for(int i=n;i>=1;i--){
		if((n-i)<a[i].val2) dp[i]=0;
		else if(dp[i+a[i].val2+1]==0) dp[i]=0; 
		else{
			if(a[i].val1>=query(i+1,i+a[i].val2)){
				dp[i]=1;
			}
		}
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		if(dp[i+1]!=0) ans=(ans+(ll)(2e5-query(1,i)+1))%mod;
	}
	cout<<ans%mod;
	return 0;
}

