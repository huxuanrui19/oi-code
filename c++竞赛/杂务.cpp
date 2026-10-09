#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
vector<int> g[N];
int n,dp[N],a[N],ind[N];
void topo_sort(){
	queue<int> q;
	for(int i=1;i<=n;i++){
		if(ind[i]==0){
			q.push(i);
			dp[i]=a[i];
		}
	}
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(auto d:g[u]){
			dp[d]=max(dp[d],dp[u]+a[d]);
			ind[d]--;
			if(!ind[d]) q.push(d);
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	for(int i=1;i<=n;i++){
		int idx=0,tmp;
		cin>>idx>>a[i]>>tmp;
		while(tmp!=0){
			g[tmp].push_back(i);
			ind[i]++;
			cin>>tmp;
		}
	}
	topo_sort();
	int ans=0;
	for(int i=1;i<=n;i++){
		ans=max(ans,dp[i]);
	}
	cout<<ans;
	return 0;
}

