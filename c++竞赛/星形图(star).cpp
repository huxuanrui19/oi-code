#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
const ll mod=1e9+7;
ll n,cnt,son[N];
vector<int> g[N];
void dfs(int u,int fa){
	son[u]=1;ll prod=1;
	for(auto d:g[u]){
		if(d==fa) continue;
		dfs(d,u);
		son[u]+=son[d];
        prod=prod*(son[d]+1)%mod;
	}
    if(g[u].size()<=2) return;
    prod=prod*(n-son[u]+1)%mod;
	ll ans=prod-n;
	ans=(ans%mod+mod)%mod;
	ll sum=n-1;
	for(auto d:g[u]){
		if(d==fa) continue;
		sum-=son[d];
		ans-=sum*son[d]%mod;
		ans=(ans%mod+mod)%mod;
	}
	cnt=(cnt+ans)%mod;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	for(int i=1,u,v;i<n;i++){
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1,0);
	cout<<cnt;
	return 0;
}

