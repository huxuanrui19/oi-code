#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10,M=20;
ll n,pre[N];
struct node{
	ll a,b;
	bool operator <(const node &x) const{
		return a>x.a;
	}
}arr[N];
multiset<ll> s;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>arr[i].a>>arr[i].b;
		s.insert(arr[i].b);
	}
	sort(arr+1,arr+n+1);
	for(int i=1;i<=n;i++){
		pre[i]=max(pre[i-1],arr[i].b);
	}
	ll ans=2e18;
	for(int i=1;i<=n;i++){
		auto pos=s.lower_bound(arr[i].b);
		s.erase(pos);
		if(i>1){
			ans=min(ans,abs(pre[i-1]-arr[i].a));
		}
		if(arr[i].a>=pre[i-1]){
			ans=min(ans,abs(arr[i].a-pre[i-1]));
			auto it=s.lower_bound(arr[i].a);
			auto itt=s.upper_bound(arr[i].a);
			if(itt!=s.begin()){
				itt--;
				if(it!=s.end()) ans=min(ans,abs(*it-arr[i].a));
				if(itt!=s.end())ans=min(ans,abs(*itt-arr[i].a));
			}
			else{
				if(it!=s.end()) ans=min(ans,abs(*it-arr[i].a));
			}
		}
		s.insert(arr[i].b);
	}
	cout<<ans;
	return 0;
}
