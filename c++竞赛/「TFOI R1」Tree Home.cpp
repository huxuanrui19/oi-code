#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
int n,t;
ll v[N],d[N];
vector<pair<int,ll> >g[N];
void dfs(int s,int fa){
	for(auto i:g[s]){
		if(i.first==fa) continue;
		d[i.first]=d[s]+i.second;
		dfs(i.first,s);
	}
	return;
}
int LOG2[N];
pair<ll,ll> dp_max[N][25];
void st_max_init(){
	LOG2[0]=-1; 
	for(int i=1;i<N;i++) LOG2[i]=LOG2[i>>1]+1;
	for(int i=1;i<=n;i++) dp_max[i][0]={d[i]*d[i]*d[i]+v[i],d[i]*d[i]*d[i]-v[i]};
	int p=LOG2[n];
	for(int i=1;i<=p;i++){
		for(int s=1;s+(1<<i)<=n+1;s++){
			dp_max[s][i].first=max(dp_max[s][i-1].first,dp_max[s+(1<<(i-1))][i-1].first);
			dp_max[s][i].second=max(dp_max[s][i-1].second,dp_max[s+(1<<(i-1))][i-1].second);
		}
	}
}
ll summax(int l,int r)
{
	int s=LOG2[r-l+1];
	return max(dp_max[l][s].first,dp_max[r-(1<<s)+1][s].first);
}
ll difmax(int l,int r)
{
	int s=LOG2[r-l+1];
	return max(dp_max[l][s].second,dp_max[r-(1<<s)+1][s].second);
}
pair<ll,ll> dp_min[N][25];
void st_min_init(){
	for(int i=1;i<=n;i++) dp_min[i][0]={d[i]*d[i]*d[i]+v[i],d[i]*d[i]*d[i]-v[i]};
	int p=LOG2[n];
	for(int i=1;i<=p;i++){
		for(int s=1;s+(1<<i)<=n+1;s++){
			dp_min[s][i].first=min(dp_min[s][i-1].first,dp_min[s+(1<<(i-1))][i-1].first);
			dp_min[s][i].second=min(dp_min[s][i-1].second,dp_min[s+(1<<(i-1))][i-1].second);
		}
	}
}
ll summin(int l,int r)
{
	int s=LOG2[r-l+1];
	return min(dp_min[l][s].first,dp_min[r-(1<<s)+1][s].first);
}
ll difmin(int l,int r)
{
	int s=LOG2[r-l+1];
	return min(dp_min[l][s].second,dp_min[r-(1<<s)+1][s].second);
}
int main(){
	cin>>n>>t;
	for(int i=1;i<=n;i++){
		cin>>v[i];
	}
	for(int i=1;i<n;i++){
		int a,b,c;
		cin>>a>>b>>c;
		g[a].push_back({b,c});
		g[b].push_back({a,c});
	}
	dfs(1,0);
	st_max_init();
	st_min_init();
	while(t--){
		int l1,r1,l2,r2;
		cin>>l1>>r1>>l2>>r2;
		cout<<max({summax(l1,r1)-summin(l2,r2),difmax(l2,r2)-difmin(l1,r1),summax(l2,r2)-summin(l1,r1),difmax(l1,r1)-difmin(l2,r2)})<<'\n';
	}
	return 0;
}

