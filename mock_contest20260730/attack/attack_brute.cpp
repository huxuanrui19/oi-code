#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
const int N=1e5+10;
ll n,m,k,cnt;
vector<pii> e;
vector<int> g[N];
inline void add(int a,int b){
	e.push_back({a,b});
	g[a].push_back(e.size()-1);
}
int num=-1,tot,dfn[N],low[N];
void tarjan(int u,int inedg){
	dfn[u]=low[u]=++tot;
	for(auto d:g[u]){
		if(num!=-1&&(d==num||d==(num^1))) continue;
		int v=e[d].second;
		if(!dfn[v]){
			tarjan(v,d);
			low[u]=min(low[v],low[u]);
			if(low[v]>dfn[u]) cnt++;
		}
		else if(d!=(1^inedg)) low[u]=min(low[u],dfn[v]);
	}
}
int main() {
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//freopen("attack.in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1,u,v;i<=m;i++){
		cin>>u>>v;
		add(u,v);add(v,u);
	}
	if(k==1){
		for(int i=1;i<=n;i++){
			if(!dfn[i]) tarjan(i,0);
		}
		cout<<cnt;
	}
	else if(k==2&&m<=2e3+10){
		ll ans=0,ans1=0;
		for(int i=1;i<=n;i++){
			if(!dfn[i]) tarjan(i,0);
		}
		ans1+=cnt;
		for(int i=0;i<e.size();i+=2){
			num=i;
			for(int j=1;j<=n;j++) low[j]=dfn[j]=0;
			cnt=tot=0;ll ti=0;
			for(int j=1;j<=n;j++){
				if(!dfn[j]) tarjan(j,0),ti++;
			}
			if(ti>1) ans+=m-1;
			else ans+=cnt;
		}
		cout<<ans/2+ans1;
	}else cout<<0;
	return 0;
}