#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
vector<pair<ll,ll> > g[N];
ll n,k,cnt=0,maxn[N][2],dis[N];
void dfs(int u,int fa,ll d){
	for(auto x:g[u]){
		ll e=x.second;ll v=x.first;
		if(v==fa) continue;
		dfs(v,u,d);
		if(dis[v]+e>d){
			cnt++;
			dis[v]=0;
		}
		if(dis[v]+e>maxn[u][0]){
			maxn[u][1]=maxn[u][0];
			maxn[u][0]=dis[v]+e;
		}
		else if(dis[v]+e>maxn[u][1]){
			maxn[u][1]=dis[v]+e;
		}
	}
	if((maxn[u][0]+maxn[u][1])>d){
		cnt++;
	}
	else dis[u]=maxn[u][0];
}
bool check(ll d){
	cnt=0;
	memset(maxn,0,sizeof(maxn));
	memset(dis,0,sizeof(dis));
	dfs(1,0,d);
	return cnt<=k;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n>>k;
	ll l=0,r=0,ans=0;
	for(int i=1;i<n;i++){
		ll u,v,w;
		cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
		r+=w;
		l=max(l,w);
	}
	while(l<=r){
		ll mid=(l+r)>>1;
		if(check(mid)){
			ans=mid;r=mid-1;
		}
		else l=mid+1;
	}
	cout<<ans;
	return 0;
}
