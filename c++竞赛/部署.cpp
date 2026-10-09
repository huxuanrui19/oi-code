#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[N],c[N],d[N],add[N];
vector<int> q[N];
void dfs(int s,int fa,int sum){
	int tmp=d[s];
	for(int i=0;i<q[s].size();i++){
		tmp+=d[q[s][i]];
		if(q[s][i]!=fa){
			dfs(q[s][i],s,sum+c[q[s][i]]);
		}
	}
	add[s]=tmp+sum+a[s];
	return;
}
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n-1;i++){
		int s,e;
		cin>>s>>e;
		q[s].push_back(e);
		q[e].push_back(s);
	}
	int m;
	cin>>m;
	for(int i=1;i<=m;i++){
		int op,x,y;
		cin>>op>>x>>y;
		if(op==1){
			c[x]+=y;
		}
		else
		{
			d[x]+=y;
		}
	}
	dfs(1,0,c[1]);
	int q;
	cin>>q;
	while(q--){
		int i;
		cin>>i;
		cout<<add[i]<<endl;
	}
	return 0;
}
