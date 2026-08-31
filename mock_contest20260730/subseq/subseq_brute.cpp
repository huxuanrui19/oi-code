#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=(1<<20)+10;
const ll mod=1e9+7;
int n,len=0;
string s,t;
void dfs(int dep){
	if(dep==n){
		t[++len]=s[dep];
		return;
	}else{
		dfs(dep+1);
		t[++len]=s[dep];
		dfs(dep+1);
		return;
	}
}
ll dp[N][2];
int main(){
	//freopen("subseq.in","r",stdin);
	//freopen("subseq.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>s;
	s=' '+s;len=pow(2,n)-1;
	t.resize(len+1);len=0;
	dfs(1);
	unordered_map<char,ll> mp;
	ll sum=1;dp[0][0]=1;
	for(int i=1;i<=len;i++){
		dp[i][0]=sum;
		dp[i][1]=(sum-mp[t[i]]+mod)%mod;
		mp[t[i]]+=dp[i][1];mp[t[i]]%=mod;
		sum=(dp[i][0]+dp[i][1])%mod;
	}
	cout<<(dp[len][0]+dp[len][1]-1)%mod;
	return 0;
}