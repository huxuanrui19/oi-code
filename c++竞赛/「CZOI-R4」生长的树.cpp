#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
ll n,k,ans=0,dep=-1,d[N]={-1},c[N]={0};
vector<int> g[N];

void bfs(){
	queue<int> q;
	q.push(1);
	d[1]=0;
	while(q.size()){
		int u=q.front();
		q.pop();
		for(auto v:g[u]){
			if(d[v]==-1){
				d[v]=d[u]+1;
				c[u]++;
				q.push(v);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	memset(d,-1,sizeof(d));
	memset(c,0,sizeof(c));
	cin>>n>>k;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	if(n==1){
		cout<<"0 0";
		return 0;
	}
	
	bfs();
	dep=0;
	for(int i=1;i<=n;i++){
		if(d[i]>dep) dep=d[i];
	}
	
	for(int i=1;i<=n;i++){
		if(d[i]<dep) ans+=(ll)(k-c[i]);
	}
	cout<<dep<<" "<<ans;
	return 0;
}

