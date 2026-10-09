#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
int n,m,f[N],son[N];
vector<int> g[N];
struct ty{
	int idx;
	bool operator> (const ty &x) const{
		return son[idx]<son[x.idx];
	}
};
vector<int> v[N];
void dfs(int u){
	son[u]=1;
	for(auto d:g[u]){
		dfs(d);
		son[u]=max(son[u],son[d]+1);
	}
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=2;i<=n;i++) cin>>f[i];
	for(int i=2;i<=n;i++) g[f[i]].push_back(i);
	dfs(1);
	int ans=0;
	priority_queue<ty,vector<ty>,greater<ty> > q;
	q.push({1});
    while(!q.empty()){
        ans++;
        for(int i=1;i<=m;i++){
            if(q.empty()) break;
            else{
                int u=q.top().idx;q.pop();
                v[ans].push_back(u);
            }
        }
        for(auto u:v[ans]){
            for(auto d:g[u]){
                q.push({d});
            }
        }
    }
	cout<<ans<<"\n";
	for(int i=1;i<=ans;i++){
		cout<<v[i].size()<<" ";
		for(auto d:v[i]) cout<<d<<" ";
		cout<<"\n";
	}
	return 0;
}