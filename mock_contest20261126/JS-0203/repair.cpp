#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e3+10;
const ll inf=1e18;
ll n,k,cnt,a[N],lis[N],dp[N][N];
unordered_map<ll,int>mp;
ll tree[N][N];
int lowbit(int x){return x&(-x);}
void update(int num,int pos,ll d){
	while(pos<N){
		tree[num][pos]=max(tree[num][pos],d);
		pos+=lowbit(pos);
	}
}
ll query(int num,int pos){
	ll ans=0;
	while(pos){
		ans=max(ans,tree[num][pos]);
		pos-=lowbit(pos);
	}
	return ans;
}
int main(){
	freopen("repair.in","r",stdin);
	freopen("repair.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>k;if(k>=n)k=n-1;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) lis[++cnt]=a[i];
	sort(lis+1,lis+cnt+1);
	cnt=unique(lis+1,lis+cnt+1)-lis-1;
	for(int i=1;i<=cnt;i++) mp[lis[i]]=i;
	if(k==0){
		int flag=1;
		for(int i=2;i<=n;i++){
			if(a[i]<a[i-1])flag=0;
		}
		if(flag==1) cout<<"0\n";
		else cout<<"-1\n";
		return 0;
	}
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++) dp[i][j]=tree[i][j]=-inf;
	}
	dp[1][0]=1;update(0,mp[a[1]],1);
	for(int i=2;i<=n;i++){
		dp[i][1]=1;
		if(a[i]>=a[i-1]) dp[i][0]=dp[i-1][0]+1;
		for(int j=1;j<=k+1;j++){
			if(a[i]>=a[i-1]) dp[i][j]=max(dp[i][j],dp[i-1][j]+1);
			dp[i][j]=max(dp[i][j],query(j,mp[a[i]])+1);
			update(j,mp[a[i]],dp[i][j]);
		}
	}
	ll ans=n;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=k;j++) ans=min(ans,n-dp[i][j]);
	}
	ans=min(ans,n-dp[n][k+1]);
	cout<<ans;
	return 0;
}
