#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e4+10;
const ll mod=998244353;
struct edge{
	int u,v;
}e[N];
ll n,m,k,cnt,lis[N<<1],dp[2][N<<1];
vector<int> g[N<<1];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m>>k;
	for(int i=1;i<=k;i++) cin>>e[i].u>>e[i].v;
	for(int i=1;i<=k;i++){
		if(e[i].u!=e[i].v){
			lis[++cnt]=e[i].u,lis[++cnt]=e[i].v;
		}
	}
	lis[++cnt]=1;
	sort(lis+1,lis+cnt+1);
	cnt=unique(lis+1,lis+cnt+1)-lis-1;
	for(int i=1;i<=k;i++){
		if(e[i].u==e[i].v) continue;
		int u=lower_bound(lis+1,lis+cnt+1,e[i].u)-lis;
		int v=lower_bound(lis+1,lis+cnt+1,e[i].v)-lis;
		g[v].push_back(u);
	}
	dp[0][1]=1;ll sum=1;
	for(int i=1;i<=m;i++){
		for(int j=0;j<=cnt;j++){
			dp[1][j]=(sum+(n-cnt)*dp[0][0]%mod)%mod;
		}
		sum=0;
		for(int j=0;j<=cnt;j++){
			for(auto d:g[j]) dp[1][j]=(dp[1][j]-dp[0][d]+mod)%mod;
			dp[1][j]=(dp[1][j]-dp[0][j]+mod)%mod;
			if(j) sum=(sum+dp[1][j])%mod;
		}
		for(int j=0;j<=cnt;j++){
			dp[0][j]=dp[1][j];dp[1][j]=0;
		}
	}
	cout<<dp[0][1];
	return 0;
}

