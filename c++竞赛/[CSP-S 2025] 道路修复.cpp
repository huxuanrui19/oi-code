#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e4+15;
int n,m,k;
vector<pair<int,ll> > g[N];
ll ans=0,c[15],a[15][N];
struct edge{
	int u,v;
	ll w;
	bool operator <(const edge &x)const{
		return w<x.w;
	}
};
vector<edge> lis;
vector<edge> e;
int fa[N];
int find(int x){
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y){
	x=find(x);y=find(y);
	fa[x]=y;
}
void k1(){
	for(int i=1;i<=n;i++) fa[i]=i;
	sort(lis.begin(),lis.end());
	int tot=0;
	for(int i=0;i<m;i++){
		int u=lis[i].u,v=lis[i].v;
		ll w=lis[i].w;
		if(find(u)==find(v)) continue;
		tot++;
		e.push_back(lis[i]);
		ans+=w;
		merge(u,v);
		if(tot==(n-1)) break;
	}
}
set<int> s;
void k2(){
	for(int i=1;i<=n+k;i++) fa[i]=i;
	int tot=0;ll cnt=0;
	for(int i=0;i<e.size();i++){
		int u=e[i].u,v=e[i].v;
		ll w=e[i].w;
		if(find(u)==find(v)) continue;
		if((u>n&&s.count(u)==0)||(v>n&&s.count(v)==0)) continue;
		tot++;
		cnt+=w;
		merge(u,v);
		if(tot==(n+s.size()-1)) break;
	}
	for(auto d:s){
		cnt+=c[d-n];
	}
	ans=min(ans,cnt);
}
int main(){
	//freopen("road.in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m>>k;
	for(int i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
		lis.push_back((edge){u,v,w});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			e.push_back(edge{i+n,j,a[i][j]}); 
		}
	}
	k1();
	sort(e.begin(),e.end());
	for(int i=0;i<(1<<k);i++){
		s.clear();
		for(int j=1;j<=k;j++){
			if(i&(1<<(j-1))) s.insert(j+n);
		}
		k2();
	}
	cout<<ans;
	return 0;
}

