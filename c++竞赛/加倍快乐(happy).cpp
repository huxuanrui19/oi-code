#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=400+10;
string s;
int n=0,c[3],p[N/2][3],dp[N/2][N/2][N/2][3];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>s;
	n=s.size();
	s=' '+s;
	for(int i=1;i<=n;i++){
		if(s[i]=='A') c[0]++,p[c[0]][0]=i;
		else if(s[i]=='C') c[1]++,p[c[1]][1]=i;
		else c[2]++,p[c[2]][2]=i;
	}
	int maxn=max({c[0],c[1],c[2]});
	if(maxn>(n+1)/2){
		cout<<"Impossible!";
		return 0;
	}
	memset(dp,0x3f,sizeof(dp)); 
	dp[0][0][0][0]=dp[0][0][0][1]=dp[0][0][0][2]=0;
	for(int i=0;i<=c[0];i++){
		for(int j=0;j<=c[1];j++){
			for(int k=0;k<=c[2];k++){
				int t=i+j+k;
				if(i) dp[i][j][k][0]=min(dp[i-1][j][k][1],dp[i-1][j][k][2])+abs(t-p[i][0]);
				if(j) dp[i][j][k][1]=min(dp[i][j-1][k][0],dp[i][j-1][k][2])+abs(t-p[j][1]);
				if(k) dp[i][j][k][2]=min(dp[i][j][k-1][0],dp[i][j][k-1][1])+abs(t-p[k][2]);
			}
		}
	}
	int ans=min({dp[c[0]][c[1]][c[2]][0],dp[c[0]][c[1]][c[2]][1],dp[c[0]][c[1]][c[2]][2]});
	cout<<ans/2;
	return 0;
}

