#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
ll n,a[N],sum[N],l[N],r[N];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	stack<int> st;
	for(int i=1;i<=n;i++){
		while(!st.empty()&&a[st.top()]>=a[i]) st.pop();
		if(st.empty()) l[i]=0;
		else l[i]=st.top();
		st.push(i);
	}
	while(!st.empty()) st.pop();
	for(int i=n;i>=1;i--){
		while(!st.empty()&&a[st.top()]>=a[i]) st.pop();
		if(st.empty()) r[i]=n+1;
		else r[i]=st.top();
		st.push(i);
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		int lt=l[i]+1,rt=r[i]-1;
		ans=max(ans,(sum[rt]-sum[lt-1])*a[i]);
	}
	cout<<ans;
	return 0;
}

