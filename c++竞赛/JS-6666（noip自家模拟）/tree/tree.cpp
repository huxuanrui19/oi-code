#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=8e3+10;
vector<int> g[N];
set<int> s[N];
int n,m,ans=0,res=0,times=0,a[N];
void solve(int u,int fa){
	s[u].insert(a[u]);
	for(auto d:g[u]){
		if(d==fa) continue;
		solve(d,u);
		for(auto val:s[d]){
			s[u].insert(val);
		}
	}
	if(!s[u].count(0)) ans+=0;
	else{
		int pre=-1,flag=1;
		for(auto d:s[u]){
			if(d!=(pre+1)){
				ans+=pre+1,flag=0;
				break;
			}
			pre=d;
		}
		if(flag==1) ans+=pre+1;
	} 
}
void dfs(int x){
	x++;
	if(x==n+1){
		ans=0;
		solve(1,0);
		times++;
		res=max(res,ans);
		return;
	}
	else{
		for(int i=0;i<n;i++){
			a[x]=i;
			dfs(x);
		}
	}
}
int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		for(int i=1;i<=n;i++){
			g[i].clear();
			s[i].clear();
		}
		
		cin>>n>>m;
		for(int i=2,u;i<=n;i++){
			cin>>u;
			g[u].push_back(i);
			g[i].push_back(u);
		}
		
		if(m==1){
			cout<<(1+n)<<"\n";
		}
		else if(m==2){
			int ans=0,maxn=0;
			for(auto d:g[1]){
				if(g[d].size()==1) ans++;
				else ans+=int(g[d].size())+1;
				maxn=max(maxn,int(g[d].size()));
			}
			cout<<(ans+maxn+1)<<"\n";
		}
		else{
			res=0;
			dfs(0);
			cout<<res<<"\n";
		}
	}
	return 0;
}

