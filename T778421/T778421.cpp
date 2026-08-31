#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
vector<int> g[N];
ll d[N];
void dfs(int u,int fa){
	d[u]=d[fa]+1;
	for(auto d:g[u]){
		if(d==fa) continue;
		dfs(d,u); 
	}
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	int n;cin>>n;
	for(int i=1,u,v;i<n;i++){
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	if(n==1){
		cout<<"3";
		return 0;
	}
	else if(n==2){
		cout<<"2";
		return 0;
	}
	d[0]=-1;
	dfs(1,0);
	ll maxn=-1,u=0;
	for(int i=1;i<=n;i++){
		if(maxn<d[i]){
			maxn=d[i];
			u=i;
		}
	}
	dfs(u,0);
	ll diam=0,cnt=0,v=0;
	for(int i=1;i<=n;i++) diam=max(diam,d[i]);
	for(int i=1;i<=n;i++) if(diam==d[i]) cnt++,v=i;
	if(cnt>=2){
		cout<<"0";return 0;
	}
	dfs(v,0);
	diam=0,cnt=0;
	for(int i=1;i<=n;i++) diam=max(diam,d[i]);
	for(int i=1;i<=n;i++) if(diam==d[i]) cnt++;
	if(cnt>=2){
		cout<<"0";return 0;
	}else cout<<"1";
	return 0;
}
