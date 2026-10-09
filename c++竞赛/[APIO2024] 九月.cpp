#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
vector<int> g[N];
int maxn[N];
void pre(int u,int fa){
	for(auto d:g[u]){
		if(d==fa) continue;
		pre(d,u);
		maxn[u]=max(maxn[d],maxn[u]);
	}
	return;
}
int solve(int n,int m,std::vector<int> F,std::vector<std::vector<int>> S){
	for(int i=0;i<N;i++) g[i].clear();
	for(int i=1;i<n;i++) g[F[i]].push_back(i);
	memset(maxn,0,sizeof(maxn));
	for(int i=0;i<m;i++){
		for(int j=0;j<n-1;j++){
			maxn[S[i][j]]=max(maxn[S[i][j]],j);
		}
	}
	pre(0,-1);
	int ma=0,ans=0;
	for(int i=0;i<n-1;i++){
		for(int j=0;j<m;j++){
			ma=max(ma,maxn[S[j][i]]);
		}
		if(ma<=i) ans++,ma=0;
	}
	return ans;
}
