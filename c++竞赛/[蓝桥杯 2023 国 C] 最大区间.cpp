#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3e5+10;
ll a[N],pre[N],nxt[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	stack<int> st;
	for(int i=1;i<=n;i++){
		while(!st.empty()&&a[st.top()]>=a[i]) st.pop();
		if(st.empty()) pre[i]=0;
		else pre[i]=st.top();
		st.push(i);
	}
	while(!st.empty()) st.pop();
	for(int i=n;i>=1;i--){
		while(!st.empty()&&a[st.top()]>=a[i]) st.pop();
		if(st.empty()) nxt[i]=n+1;
		else nxt[i]=st.top();
		st.push(i);
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		ans=max(ans,a[i]*(nxt[i]-pre[i]-1));
	}
	cout<<ans;
	return 0;
}

