#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1.5e5+10;
struct node{
	ll t1,t2;
	bool operator <(const node &x) const{
		if(t2!=x.t2) return t2<x.t2;
		else return t1<x.t1;
	} 
}a[N];
ll n,ans,sum;
priority_queue<int,vector<int>,less<int> > q;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i].t1>>a[i].t2;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum+=a[i].t1;q.push(a[i].t1);ans++;
		if(sum>a[i].t2){
			--ans;sum-=q.top();q.pop();
		}
	}
	cout<<ans;
	return 0;
}