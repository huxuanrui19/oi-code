#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
template < typename T >
void read(T &x){
	x=0;int f=1;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f*=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=(x<<1)+(x<<3)+(ch&15);
		ch=getchar(); 
	}
	x*=f;
}
const int N = 1e5 + 10;
const ll mod=998244353;
ll n,ans,a[N],fa[N],siz[N],flag[N];
vector<int> g[N];
inline ll qp(ll n,ll k){
	ll sum=1;
	while(k){
		if(k&1) sum=sum*n%mod;
		n=n*n%mod;
		k>>=1;
	}
	return sum;
}

vector<pii> e[N];
set<int> s;

int find(int x){return (fa[x]==x)?x:find(fa[x]);}
inline void merge(int u,int v){
	u=find(u);v=find(v);
	fa[u]=v;siz[v]+=siz[u];
}
int main(){
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int t;read(t);
	while(t--){
		read(n);
		for(int i=1;i<n;i++){
			int u,v;read(u);read(v);
			g[u].push_back(v);
		}
		for(int i=1;i<=n;i++) read(a[i]);
		for(int i=1;i<=n;i++){
			for(auto d:g[i]){
				ll x=__gcd(a[i],a[d]);
				for(int t=1;t*t<=x;t++){
					if(x%t) continue;
					e[t].push_back({i,d});
					s.insert(t);
					if(t*t==x) continue;
					e[x/t].push_back({i,d});
					s.insert(x/t);
				}
			} 
		}
		ll ans=0;
		for(auto t:s){
			ll A=0,B=0;
			for(auto d:e[t]){
				int u=d.first,v=d.second;
				fa[u]=u;fa[v]=v;siz[u]=1;siz[v]=1;flag[u]=flag[v]=0;
			}
			for(auto d:e[t]){
				int u=d.first,v=d.second;
				merge(u,v);
			}
			for(auto d:e[t]){
				int u=d.first,v=d.second;
				if(fa[v]==v&&!flag[v]) A=(A+siz[v]*(siz[v]-1)/2%mod)%mod,flag[v]=1;
				if(fa[u]==u&&!flag[u]) A=(A+siz[u]*(siz[u]-1)/2%mod)%mod,flag[u]=1;
			}
			for(auto d:e[t]){
				int u=d.first,v=d.second;
				fa[u]=u;fa[v]=v;siz[u]=1;siz[v]=1;flag[u]=flag[v]=0;
			}
			for(auto d:e[t]){
				int u=d.first,v=d.second;
				if(a[u]==t||a[v]==t) continue;
				merge(u,v);
			}
			for(auto d:e[t]){
				int u=d.first,v=d.second;
				if(fa[v]==v&&!flag[v]) B=(B+siz[v]*(siz[v]-1)/2%mod)%mod,flag[v]=1;
				if(fa[u]==u&&!flag[u]) B=(B+siz[u]*(siz[u]-1)/2%mod)%mod,flag[u]=1;
			}
			ans=(ans+(A-B+mod)*t%mod)%mod;
		}
		cout<<(ans*qp(n*(n-1)/2%mod,mod-2)%mod)<<"\n";
		ans=0;
		for(int i=1;i<=n;i++) g[i].clear();
		for(int i=1;i<=n;i++) e[i].clear();
		for(int i=1;i<=n;i++) flag[i]=0;
	}
	return 0;
}