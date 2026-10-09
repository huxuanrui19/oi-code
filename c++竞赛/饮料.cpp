#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
ll t[N],a[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>t[i];
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(t[i]<i){
			cout<<"-1";
			return 0;
		}
	}
	stack<ll> st;
	for(int i=n;i>=0;i--){
		if(i!=n){
			for(int j=1;j<=t[i+1]-t[i];j++){
				if(!st.empty()){
					ans+=st.top();
					st.pop();
				}
				else break;
			}
		}
		if(!i) break;
		if(!st.empty()) st.push(max(st.top(),a[i]));
		else st.push(a[i]);
	}
	cout<<ans;
	return 0;
}

