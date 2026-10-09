#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
const int N=2e5+10;
int n;
struct node{
	ll t,w,type;
	bool operator <(const node &x) const{
		if(t!=x.t) return t<x.t;
		else return w>x.w;
	}
}a[N];
priority_queue<pii,vector<pii>,less<pii> > q;
ll m,ans,cnt[N],num[N];
int main() {
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i].t>>a[i].w>>a[i].type;
	sort(a+1,a+n+1);
	priority_queue<int,vector<int>,greater<int> > q1;
	priority_queue<int,vector<int>,greater<int> > q2;
	for(int i=1;i<=n;i++){
		if(a[i].type) q1.push(a[i].w);
		else q2.push(a[i].w);
		if(q1.size()+q2.size()>a[i].t){
			if(!q2.empty()) q2.pop();
			else q1.pop();
		}
	}
	cout<<q1.size()<<" ";
	ll ans=0;
	while(!q1.empty()){
		ans+=q1.top();q1.pop();
	}
	while(!q2.empty()){
		ans+=q2.top();q2.pop();
	}
	cout<<ans;
	return 0;
}

