#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		ll a,b,c,d;
		cin>>a>>b>>c>>d;
		ll ans=0;
		while(a!=c||b!=d){
			ll tmp=0;
			if((c-a)>=d){
				tmp=(c-a)/d;
				c-=tmp*d;
				ans+=tmp;
			}
			else if((d-b)>=c){
				tmp=(d-b)/c;
				d-=tmp*c;
				ans+=tmp;
			}
			else{
				ans=-1;
				break;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

