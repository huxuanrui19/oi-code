#include<bits/stdc++.h>
#define pii pair<ll,pair<int,int> >
using namespace std;
typedef long long ll;
const int N=1e5+10;
int n,a[N],b[N];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i];
	priority_queue<pii,vector<pii>,greater<pii> > q;
	for(int i=1;i<=n;i++){
		q.push({a[i]+b[1],{i,1}}); 
	}
	for(int i=1;i<=n;i++){
		pii p=q.top();q.pop();
		int u=p.first,v=p.second.first,w=p.second.second;
		cout<<u<<" ";
		if(w==n) continue;
		else q.push({a[v]+b[w+1],{v,w+1}});
	}
	return 0;
}

