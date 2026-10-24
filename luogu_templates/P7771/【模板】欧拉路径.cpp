#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
vector<int> g[N]; 
int ind[N],outd[N],now[N];
stack<int> sta;
void dfs(int u){
	for(int i=now[u];i<g[u].size();i=now[u]){
		now[u]=i+1;
		dfs(g[u][i]);
	}
	sta.push(u);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		outd[u]++;
		ind[v]++;
	}
	int st=0,ed=0,s=1;
	for(int i=1;i<=n;i++){
		if(outd[i]==ind[i]) continue;
		if(outd[i]==ind[i]+1){st++;s=i;}
		else if(outd[i]==ind[i]-1) ed++;
		else{
			cout<<"No";
			return 0;
		}
	}
	if((!(ed==1&&st==1))&&(!(ed==0&&st==0))){
		cout<<"No";
		return 0;
	}
	for(int i=1;i<=n;i++){
		sort(g[i].begin(),g[i].end());
	}
	dfs(s);
	while(!sta.empty()){
		cout<<sta.top()<<" ";
		sta.pop();
	}
	return 0;
}

