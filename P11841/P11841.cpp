#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
ll T,a,b,c,d;
ll solve(){
	ll ans=0;
	while(a!=c||b!=d){
		ll cnt=0;
		if((c-a)>=d){
			cnt+=(c-a)/d;
			c-=cnt*d;
			ans+=cnt;
		}
		else if((d-b)>=c){
			cnt+=(d-b)/c;
			d-=cnt*c;
			ans+=cnt;
		}
		else return -1;
	}
	return ans;
}
int main() {
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>T;
	while(T--){
		cin>>a>>b>>c>>d;
		cout<<solve()<<"\n";
	}
	return 0;
}
