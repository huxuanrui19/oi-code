#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e3+10,M=2e5+10;
int n,lt,rt,a[M],dp[N][N],l[M],r[M];
string s;
void dp1(){
	memset(dp,-0x3f,sizeof(dp));
	dp[0][0]=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=n;j++){
			dp[i][j]=dp[i-1][j];
			if(s[i]=='('&&j) dp[i][j]=max(dp[i][j],dp[i-1][j-1]+a[i]);
			if(s[i]==')') dp[i][j]=max(dp[i][j],dp[i-1][j+1]+a[i]);
		}
	}
	cout<<dp[n][0];
}
void gr(){
	for(int i=1;i<=n;i++){
		if(s[i]=='(') l[++lt]=a[i];
		else r[++rt]=a[i];
	}
	sort(l+1,l+lt+1,greater<int>());
	sort(r+1,r+rt+1,greater<int>());
	int ans=0;
	for(int i=1;i<=min(lt,rt);i++){
		if(l[i]+r[i]>=0) ans+=l[i]+r[i];
		else break;
	}
	cout<<ans;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>s;
	s=' '+s;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=2e3) dp1();
	else gr();
	return 0;
}

