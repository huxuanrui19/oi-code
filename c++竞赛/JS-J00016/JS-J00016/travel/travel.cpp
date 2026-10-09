#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
ll n,m,p;
int fa[N];
int find(int x){
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y){
	x=find(x);
	y=find(y);
	fa[x]=y;
	return;
}
struct edge{
	ll u,v,w;
	bool operator <(const edge &x) const{
		if(w<=p&&x.w>p) return 1;
		if(w<=p&&x.w<=p) return w>x.w;
		return w<x.w;
	}
}e[N];
ll kruskal(){
	for(int i=1;i<=n;i++) fa[i]=i;
	int cur=0,flag=0;
	ll lst=1e15;
	for(int i=1;i<=m;i++){
		if(cur==(n-1)) return lst; 
		int u=e[i].u,v=e[i].v,w=e[i].w;
		if(find(u)==find(v)) continue;
		merge(u,v);
		if(w<=p) lst=min(lst,p-w);
		else{
			if(flag==0){
				lst=0;
				flag=1;
			}
			lst+=e[i].w-p;
		}
		cur++;
	}
	return lst;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		ll u,v,w;
		cin>>u>>v>>w;
		e[i]={u,v,w};
	}
	cin>>p;
	sort(e+1,e+m+1);
	ll cnt=kruskal();
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

