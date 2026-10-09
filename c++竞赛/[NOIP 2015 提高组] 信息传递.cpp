#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
vector<int> g[N];
vector<int> a[N];
stack<int> st;
int ans=1e9,times=0,cnt=0,dfn[N],low[N],in[N],size[N];
void tarjan(int u){
	dfn[u]=low[u]=++times;
	st.push(u);
	in[u]=1;
	for(int v:g[u]){
		if(!dfn[v]){
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else if(in[v]==1) low[u]=min(low[u],dfn[v]);
	}
	if(low[u]==dfn[u]){
		cnt++;
		int sum=0;
		while(st.top()!=u){
			a[cnt].push_back(st.top());
			in[st.top()]=0;
			st.pop();
            size[cnt]++;
			sum++;
		}
		a[cnt].push_back(st.top());
		in[st.top()]=0;
		st.pop();
		sum++;
        size[cnt]++;
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
        cin>>x;
        g[i].push_back(x);
	}
	for(int i=1;i<=n;i++){
		if(!dfn[i]){
			tarjan(i);
		}
	}
    for(int i=1;i<=cnt;i++){
        if(size[i]>=2) ans=min(ans,size[i]);
    }
	cout<<ans;
	return 0;
}
