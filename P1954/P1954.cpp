#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e3+10;
int n,m,k[N],ind[N],s[N],ans[N];
vector<int> g[N];
vector<int> v[N];
struct que{
	int bg,ed,q[N];
	void init(){bg=ed=1;}
	bool empty(){return ed==bg;}
	void push(int u){q[ed++]=u;}
	void pop(){q[bg++]=0;}
	int front(){return q[bg];}
	bool judge(int u){
		if(bg+1==ed) return 0;
		else{
			swap(q[bg],q[bg+1]);
			return 1;
		}
	}
}q1,q2;
void solve1(){
	vector<int> locktime;
	locktime.resize(n+1);
	for(int i=1;i<=n;i++) locktime[i]=ind[i]+1;
	for(int t=n;t>=1;t--){
		for(auto d:v[t]){
			locktime[d]--;
			if(locktime[d]==0) q1.push(d);
		}
		int u=q1.front();q1.pop();
        s[t]=u;
		for(auto d:g[u]){
			locktime[d]--;
			if(locktime[d]==0) q1.push(d);
		}
	}
}
ll solve2(int tar){
	q2.init();
	vector<int> locktime;
	locktime.resize(n+1);
	for(int i=1;i<=n;i++) locktime[i]=ind[i]+1;
	for(int t=n;t>=1;t--){
		for(auto d:v[t]){
			locktime[d]--;
			if(locktime[d]==0&&d!=tar) q2.push(d);
		}
		if(q2.empty()) return t;
		int u=q2.front();q2.pop();
		for(auto d:g[u]){
			locktime[d]--;
			if(locktime[d]==0&&d!=tar) q2.push(d);
		}
	}
	return -1;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>k[i];
	for(int i=1;i<=n;i++) v[k[i]].push_back(i);
	for(int i=1;i<=m;i++){
		int u,v;cin>>u>>v;
		g[v].push_back(u);
		ind[u]++;
	}
	solve1();
	for(int i=1;i<=n;i++) ans[i]=solve2(i);
	for(int i=1;i<=n;i++) cout<<s[i]<<" ";
	cout<<"\n";
	for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
	return 0;
}
