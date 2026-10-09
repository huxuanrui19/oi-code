#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e3+10;

vector<int> g[N];
ll n,m,a[N],b[N],dp[N],suf[N],trans[N],ind[N];
struct node{
	ll a,b,id,out;
}arr[N];
void topo_sort(){
	queue<int> q;
	stack<int> st;
	for(int i=1;i<=n;i++){
		if(ind[i]==0){
			q.push(i);
		}
	}
	while(!q.empty()){
		int u=q.front();
		q.pop();
		st.push(u);
		for(auto d:g[u]){
			ind[d]--;
			if(!ind[d]) q.push(d);
		}
	}
	int cnt=0;
	while(!st.empty()){
		arr[++cnt]=(node){a[st.top()],b[st.top()],st.top(),int(g[st.top()].size())};
		st.pop();
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i];
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		if(a[u]>a[v]) g[u].push_back(v),ind[v]++;
		if(a[v]>a[u]) g[v].push_back(u),ind[u]++;
	}
	topo_sort();
	for(int i=1;i<=n;i++){
		trans[arr[i].id]=i;
	}
	
	for(int i=1;i<=n;i++){
		if(arr[i].out==0){
			suf[i]=1;
			continue;
		}
		memset(dp,0,sizeof(dp));
		for(auto d:g[arr[i].id]){
			for(int j=arr[i].a;j>a[d];j--){
				dp[j]=max(dp[j],dp[j-a[d]]+suf[trans[d]]);
			}
		}
		suf[i]=1;
		for(int j=0;j<=arr[i].a;j++){
			suf[i]=max(suf[i],dp[j]+1); 
		}
	}
	
	ll ans=0;
	for(int i=1;i<=n;i++){
		ans+=1ll*arr[i].b*suf[i];
	}
	cout<<ans;
	return 0;
}

