#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e4+10;
const ll mod=1e9+7;
int n,m,fa[N];
ll dis[N];
ll qp(ll n,ll k){
	ll sum=1;
	while(k){
		if(k&1) sum=sum*n%mod;
		n=n*n%mod;k>>=1;
	}
	return sum;
}
int find(int x){
	if(x==fa[x]) return x;
	else{
		int root=find(fa[x]);
		dis[x]=dis[x]*dis[fa[x]]%mod;
		fa[x]=root;return fa[x];
	}
}
bool merge(int u,int v,ll w){
	int ru=find(u),rv=find(v);
	if(ru==rv){
		if(dis[u]*qp(dis[v],mod-2)%mod!=w) return false;
		else return true;
	}
	else{
		fa[rv]=ru;
		dis[rv]=dis[u]*qp(dis[v],mod-2)%mod*qp(w,mod-2)%mod;
	}
	return true;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	int t,idx=0;cin>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;i++) fa[i]=i,dis[i]=1;
		bool flag=1;
		for(int j=1;j<=m;j++){
			int u,v;ll x,y,w;
			cin>>u>>v>>x>>y;w=(x+mod)%mod*qp((y+mod)%mod,mod-2)%mod;
			flag=flag&&merge(u,v,w);
		}
		idx++;
		cout<<"Case #"<<idx<<": ";
		if(flag==1) cout<<"Yes\n";
		else cout<<"No\n";
	} 
	return 0;
}
