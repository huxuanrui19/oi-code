const int N=1e5+10;
ll a[N];
void stack_min_build(){
	stack<ll> st;
	for(int i=1;i<=n;i++){
		while(!st.empty()&&a[st.top()]<=a[i]){
			st.pop();
		}
		pre[i]= (st.empty() ? 0:st.top());
		st.push(i);
	}
	while(!st.empty()) st.pop();
	for(int i=n;i>=1;i--){
		while(!st.empty()&&a[st.top()]<=a[i]){
			st.pop();
		}
		nxt[i]=(st.empty() ? n+1:st.top());
		st.push(i);
	}
}
