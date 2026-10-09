#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e3+10,M=2e5+10;
int n,a[M],dp[N][N],lt,rt,l[M],r[M];
string s;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>s;
	s=' '+s;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=20){
		int ans=0;
		for(int i=0;i<(1<<n);i++){
			int cnt=0,tot=0,flag=0;
			for(int j=1;j<=n;j++){
				if(i&(1<<(j-1))){
					cnt+=a[j];
					if(s[j]=='(') tot++;
					else{
						tot--;
						if(tot<0) flag=1;
					}
				} 
			}
			if(flag!=1&&tot==0) ans=max(ans,cnt); 
		}
		cout<<ans;
	}
	else if(n<=2e3){
        memset(dp,-0x3f,sizeof(dp));
        dp[0][0]=0;
		for(int i=1;i<=n;i++){
			for(int j=0;j<=n;j++){
				dp[i][j]=dp[i-1][j];
				if(s[i]=='('&&j) dp[i][j]=max(dp[i-1][j-1]+a[i],dp[i][j]);
				if(s[i]==')') dp[i][j]=max(dp[i-1][j+1]+a[i],dp[i][j]);
			}
		}
		cout<<dp[n][0];
	}
	else{
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
	return 0;
}
