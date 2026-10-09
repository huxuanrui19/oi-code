#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int flag[N]={0};
vector<int> g[N];
queue<int> q;
void dfs(int s){
	cout<<s<<" ";
	flag[s]=1;
	for(int i=0;i<g[s].size();i++){
		if(flag[g[s][i]]==0){
			dfs(g[s][i]);
		}
	}
	return;
}
void bfs(){
	q.push(1);
	flag[1]=1;
	while(!q.empty()){
		int s=q.front();
		cout<<s<<" ";
		q.pop();
		flag[s]=1;
		for(int i=0;i<g[s].size();i++){
			if(!flag[g[s][i]]){
				q.push(g[s][i]);
				flag[g[s][i]]=1;
			}
		}
	}
	return;
}
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int s,e;
		cin>>s>>e;
		g[s].push_back(e);
	}
	for(int i=1;i<=n;i++){
		sort(g[i].begin(),g[i].end());
	}
	dfs(1);
	cout<<endl;
	for(int i=1;i<=n;i++){
		flag[i]=0;
	}
	bfs();
}
