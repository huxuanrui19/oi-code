#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
vector<int>g;
ll dp[65][2][2];
ll dfs(int pos,int mark,int last){
	if(pos==-1) return 1;
	if(dp[pos][mark][last]!=-1) return dp[pos][mark][last];
	ll ans=0;
	for(int i=0;i<=1;i++){
		if(last&&i) break;
		if((mark==0)&&i>g[pos]) break;
		ans+=dfs(pos-1,mark|(i<g[pos]),i);
	}
	return dp[pos][mark][last]=ans;
}
ll cal(ll x){
	if(x==-1) return 0;
	g.clear();
	while(x){
		g.push_back(x&1);
		x>>=1;
	}
	memset(dp,-1,sizeof(dp));
	return dfs(g.size()-1,0,0);
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		ll l,r;
		cin>>l>>r;
		cout<<cal(r)-cal(l-1)<<"\n";
	} 
	return 0;
}

