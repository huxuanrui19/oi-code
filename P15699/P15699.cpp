#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2.5e5+10;
struct node{
	ll l,d;
	bool operator <(const node &x) const{
		if(l+d!=x.d+x.l) return l+d<x.d+x.l;
		else return l<x.l;
	}
}cnt[N]; 
int n;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>cnt[i].l>>cnt[i].d;
	}
	sort(cnt+1,cnt+n+1);
	ll sum=0;priority_queue<ll,vector<ll>,less<ll> > q;
	for(int i=1;i<=n;i++){
		q.push(cnt[i].d);sum+=cnt[i].d;
		if(sum<=cnt[i].d+cnt[i].l) continue;
		else{
			sum-=q.top();q.pop();
		}
	}
	cout<<q.size();
	return 0;
}
