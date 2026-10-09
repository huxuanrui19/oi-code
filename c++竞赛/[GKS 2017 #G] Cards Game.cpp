#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100+10;
ll n,cnt,ans,r[N],b[N];int fa[N];
struct edge{
	ll u,v,w;
	bool operator <(const edge &x) const{
		return w<x.w;
	}
}e[N*N];
int find(int x){return (x==fa[x])?x:(fa[x]=find(fa[x]));}
void merge(int u,int v){
	u=find(u);v=find(v);
	fa[u]=v;
}
void kruskal(){
	ans=0;
	for(int i=1;i<=n;i++) fa[i]=i;
	sort(e+1,e+cnt+1);int tot=0;
	for(int i=1;i<=cnt;i++){
		int u=e[i].u,v=e[i].v;ll w=e[i].w;
		if(find(u)==find(v)) continue;
		ans+=w;merge(u,v);tot++;
		if(tot==n-1) return;
	}
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	int t,idx=0;cin>>t;
	while(t--){
		cin>>n;idx++;cnt=0;
		for(int i=1;i<=n;i++) cin>>r[i];
		for(int i=1;i<=n;i++) cin>>b[i];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				else e[++cnt]={i,j,r[i]^b[j]};
			}
		}
		kruskal();
		cout<<"Case #"<<idx<<": ";
		cout<<ans<<"\n"; 
	}
	return 0;
}
