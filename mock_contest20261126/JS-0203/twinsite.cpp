#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=7e2+10,M=2e5+10,S=1<<16;
const ll inf=1e18;
vector<pair<int,ll> > g[M];
int n,m,a[M],b[M],vis[M];
ll d1[M];
void dfs1(int u,int fa){
	for(auto d:g[u]){
		int v=d.first;
		if(v==fa) continue;
		d1[v]=d1[u]+d.second;
		dfs1(v,u);
	}
}
int f[20][M],dep[M],dis[M];
void dfs(int u,int fa,ll inval){
	f[0][u]=fa;dis[u]=dis[fa]+inval;
	dep[u]=dep[fa]+1;
	for(int j=1;j<20;j++){
		f[j][u]=f[j-1][f[j-1][u]];
	}
	for(auto d:g[u]){
		if(d.first==fa) continue;
		dfs(d.first,u,d.second);
	}
}
int lca(int u,int v){
	if(u==v) return u;
	if(dep[u]<dep[v]) swap(u,v);
	for(int j=19;j>=0;j--){
		if(dep[f[j][u]]<dep[v]) continue;
		u=f[j][u];
	}
	if(u==v) return u;
	for(int j=19;j>=0;j--){
		if(f[j][u]!=f[j][v]){
			u=f[j][u];v=f[j][v];
		}
	}
	return f[0][u];
}
ll dist(ll u,ll v){
	return dis[u]+dis[v]-2*dis[lca(u,v)];
}
vector<int> getstatus(int seed){
	srand(seed);
	vector<int> v;v.resize(m+1);
	for(int i=1;i<=m;i++){
		int num=abs(rand()%2);
		v[i]=num;
	}
	return v;
}
int main(){
	freopen("twinsite.in","r",stdin);
	freopen("twinsite.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<n;i++){
		int u,v,w;cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	for(int i=1;i<=m;i++) cin>>a[i]>>b[i];
	int flag=1;
	for(int i=1;i<=m;i++){
		if(a[i]!=b[i]) flag=0;
	}
	if(m==1) cout<<"0\n";
	else if(flag){
		dfs1(a[1],0);
		ll maxn=0,idx=0;
		for(int i=1;i<=m;i++){
			if(d1[a[i]]>maxn){
				maxn=d1[a[i]],idx=a[i];
			}
		}
		d1[idx]=0;
		dfs1(idx,0);
		maxn=0;
		for(int i=1;i<=m;i++){
			maxn=max(maxn,d1[a[i]]);
		}
		cout<<maxn<<"\n";
	}
	else if(m<=10){
		dfs(1,1,0);
		ll ans=inf;
		for(int i=0;i<(1<<m);i++){
			int pt[m+1];
			for(int j=0;j<m;j++){
				if(i&(1<<j)) pt[j+1]=a[j+1];
				else pt[j+1]=b[j+1];
			}
			ll maxn=0;
			for(int j=1;j<=m;j++){
				for(int k=j+1;k<=m;k++){
					maxn=max(maxn,dist(pt[k],pt[j]));
					if(maxn>=ans) goto nxt;
				}
			}
			ans=min(ans,maxn);
			nxt:;
		}
		cout<<ans<<"\n";
	}
	else{
		int times=300;
		vector<int>v;v.resize(m+1);
		ll ans=inf;
		while(times--){
			v=getstatus(times);
			vector<int> l;
			for(int i=1;i<=m;i++){
				if(v[i]) l.push_back(a[i]);
				else l.push_back(b[i]);
			}
			d1[l[0]]=0;
			dfs1(l[0],0);
			ll maxn=0,idx=0;
			for(int i=1;i<=m;i++){
				if(d1[l[i-1]]>maxn){
					maxn=d1[l[i-1]],idx=l[i-1];
				}
			}
			d1[idx]=0;
			dfs1(idx,0);
			maxn=0;
			for(int i=1;i<=m;i++){
				maxn=max(maxn,d1[l[i-1]]);
			}
			ans=min(ans,maxn);
		}
		cout<<ans<<"\n";
	}
	return 0;
}
