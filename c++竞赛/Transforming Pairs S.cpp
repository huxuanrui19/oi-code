#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b,c,d;
ll kkk(){
	ll ans=0;
	while(a!=c||b!=d){
		if(c-a>=d){
			ll x=(c-a)/d;
			ans+=x;
			c-=x*d;
		}else if(d-b>=c){
			ll x=(d-b)/c;
			ans+=x;
			d-=x*c;
		}
		else{
			ans=-1;
			break;
		}
	}
	return ans;
} 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		cin>>a>>b>>c>>d;
		cout<<kkk()<<endl;
	}
	return 0;
}

