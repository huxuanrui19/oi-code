#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=998244353;
const int N=1e5+10;
struct node{
	ll x,d;
	bool operator <(const node &tmp) const{
		return x<tmp.x; 
	}
}p[N];
ll n,cnt=0,dp[N][2],nxt[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>p[i].x>>p[i].d;
	}
	sort(p+1,p+n+1);
	stack<pair<int,ll>> st;
	for(int i=n;i>=1;i--){
		ll dis=p[i].x+p[i].d-1;
		while(!st.empty()&&p[st.top().first].x<=dis){
			dis=max(dis,st.top().second);
			st.pop();
		}
		if(st.empty()) nxt[i]=n+1;
		else nxt[i]=st.top().first;
		st.push(make_pair(i,dis));
	}
	dp[n][1]=dp[n][0]=1;
	for(int i=n-1;i>=1;i--){
        dp[i][0]=(dp[i+1][1]+dp[i+1][0])%mod;
		if(nxt[i]==n+1){
            dp[i][1]=1;
        }
		else{
			dp[i][1]=(dp[nxt[i]][1]+dp[nxt[i]][0])%mod;
		}
	}
	cout<<(dp[1][0]+dp[1][1])%mod;
	return 0;
}
