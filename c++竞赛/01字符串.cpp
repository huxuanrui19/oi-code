#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
struct sub{
	string s;
	int qian,hou,id;
	bool operator <(const sub &a) const{
		if(qian!=a.qian) return qian<a.qian;
		return id<a.id;
	}
}t[N];
int tmp[N],vis[N];
pair<int,int> g[N];
stack<int> sta;
void dfs(int u){
	vis[u]=1;
	for(int i=g[u].first;i<=g[u].second;i++){
		if(!vis[i]){
			g[u].first++;
			dfs(i);
		}
	}
	sta.push(t[u].id);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("string4.in","r",stdin);
	int n,m,b;
	cin>>n>>m>>b;
	for(int i=1;i<=n;i++){
		cin>>t[i].s;
		int last=0;
		for(int j=0;j<t[i].s.size();j++){
			if(t[i].s[j]=='1'){
				if(last==0){
					last=j;
					t[i].qian=last;
					continue;
				}
				else{
					if((j-last)%m!=0){
						cout<<"-1";
						return 0;
					}
					last=j;
				}
			}
		}
		t[i].hou=t[i].s.size()-1-last;
		t[i].id=i;
	}
	sort(t+1,t+n+1);
	for(int i=1;i<=n;i++){
		tmp[i]=t[i].qian;
	}
	for(int i=1;i<=n;i++){
		int tar=m-1-t[i].hou;
		int l=lower_bound(tmp+1,tmp+n+1,tar)-tmp;
		int r=upper_bound(tmp+1,tmp+n+1,tar)-tmp-1;
		if(l>n){
			cout<<"-1";
			return 0;
		}
		g[i]={l,r};
	}
	int st=1e9,minid=1e9;
	for(int i=1;i<=n;i++){
		if(t[i].qian==b&&minid>t[i].id){
			minid=t[i].id;
			st=i;
		}
	}
	dfs(st);
	if(sta.size()!=n){
		cout<<"-1";
		return 0;
	}
	while(!sta.empty()){
		cout<<sta.top()<<" ";
		sta.pop();
	}
	return 0;
}

