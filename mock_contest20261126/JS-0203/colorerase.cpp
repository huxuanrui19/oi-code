#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=4e3+10;
const ll inf=1e18;
int n,x[N],c[N];
ll dp[N][N];
int main(){
	freopen("colorerase.in","r",stdin);
	freopen("colorerase.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>x[i];
	for(int i=1;i<=n;i++) cin>>c[i];
	if(n>=500){
		stack<int> st;
		ll ans=0;
		for(int i=1;i<=n;i++){
			if(st.empty()) st.push(i);
			else if(c[st.top()]!=c[i]){
				ans+=x[i]-x[st.top()];
				st.pop();
			}else st.push(i);
		}
		if(!st.empty()) cout<<"-1\n";
		else cout<<ans<<"\n";
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) dp[i][j]=inf;
	}
	for(int i=1;i<n;i++){
		if(c[i]!=c[i+1]) dp[i][i+1]=x[i+1]-x[i];
	}
	for(int len=4;len<=n;len+=2){
		for(int i=1;i+len-1<=n;i++){
			int j=i+len-1;
			if(c[j]!=c[i]) dp[i][j]=min(dp[i][j],dp[i+1][j-1]+x[j]-x[i]);
			for(int k=i+2;k<=j;k+=2){
				dp[i][j]=min(dp[i][j],dp[i][k-1]+dp[k][j]);
			}
		}
	}
	if(dp[1][n]==inf) cout<<"-1";
	else cout<<dp[1][n];
	return 0;
}
