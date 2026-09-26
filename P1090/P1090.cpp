#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e4+10;
ll n,ans,a[N];
priority_queue<int,vector<int>,greater<int> >q; 
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) q.push(a[i]);
	while(q.size()>1){
		ll u=q.top();q.pop();
		ll v=q.top();q.pop();
		ans+=(u+v);q.push(u+v);
	}
	cout<<ans;
	return 0;
}
