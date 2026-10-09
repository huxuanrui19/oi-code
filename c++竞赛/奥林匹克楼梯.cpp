#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
int sum[N],pre[N],val[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int h,w;
	cin>>h>>w;
	int ans=-1;
	for(int i=1;i<=h;i++){
		for(int j=1;j<=w;j++){
			char a;
			cin>>a;
			sum[j]=(a=='1' ? sum[j]+1:0);
		}
		stack<int> st;
		for(int j=1;j<=w;j++){
			while(!st.empty()&&sum[st.top()]>sum[j]){
				pre[st.top()]=j;
				st.pop();
			}
			st.push(j);
		}
		while(!st.empty()){
			pre[st.top()]=w+1;
			st.pop();
		}
		for(int j=w;j>=1;j--){
			val[j]=val[pre[j]]+sum[j]*(pre[j]-j);
			ans=max(ans,val[j]);
		}
	}
	cout<<ans;
	return 0;
}

