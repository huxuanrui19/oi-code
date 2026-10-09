#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e4+10;
const int M=2e5+10;
struct edge{
	int u,v,w;
	bool operator <(const edge &a) const{
		if(w!=a.w) return w<a.w;
		if(u!=a.u) return u<a.u;
		return v<a.v;
	}
}e[M];
int fa[N];
int find(int u){
	if(u==fa[u]) return u;
	return fa[u]=find(fa[u]);
}
void merge(int u,int v){
	u=find(u);
	v=find(v);
	fa[u]=v;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	for(int i=1;i<=n;i++) fa[i]=i;
	sort(e+1,e+m+1);
	int ans=0,tot=0;
	for(int i=1;i<=m;i++){
		if(find(e[i].u)==find(e[i].v)) continue;
		merge(e[i].u,e[i].v);
		tot++;
		ans+=e[i].w;
	}
	if(tot<(n-1)) cout<<"orz";
	else cout<<ans;
	return 0;
}

