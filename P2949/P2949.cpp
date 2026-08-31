#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
struct node{
	ll d,p;
	bool operator <(const node &x) const{
		return d<x.d;
	}
}a[N];
ll n,ans=0,sum=0;
priority_queue<int,vector<int>,greater<int> > q;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i].d>>a[i].p;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum++;q.push(a[i].p);ans+=a[i].p;
		if(sum>a[i].d){
			ans-=q.top();sum--;q.pop();
		}
	}
	cout<<ans;
	return 0;
}
