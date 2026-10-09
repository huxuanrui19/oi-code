#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
typedef long long ll;
const int N=2e5+10;
vector<int> g[N];
vector<pii> gt[N];
map<int,int> mp[N];
ll n,m,ind[N],a[N];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		gt[u].push_back({v,w});
		if(!mp[v].count(u)) g[v].push_back(u),ind[u]++,mp[v][u]=1;
		if(!mp[w].count(u)) g[w].push_back(u),ind[u]++,mp[w][u]=1;
	}
	queue<int> q;
	for(int i=1;i<=n;i++){
		if(ind[i]==0){
			a[i]=1;
			q.push(i);
		}
	}
	int num=0;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		num++;
		for(auto d:g[u]){
			ind[d]--;
			if(ind[d]==0) q.push(d);
		}
		for(auto d:gt[u]){
			int v=d.first,w=d.second;
			a[u]=max(a[u],a[v]+a[w]);
		}
	}
	ll ans=0;
	for(int i=1;i<=n;i++) ans+=a[i];
	if(num!=n||ans>1e9) cout<<"-1";
	else cout<<ans;
	return 0;
}

