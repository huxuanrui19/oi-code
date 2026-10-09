#include<bits/stdc++.h>
using namespace std;
long long dp[32][20005],t[32],c[32];
int main(){
	int T,m;
	cin>>T>>m;
	for(int i=1;i<=m;i++){
		cin>>t[i];
		c[i]=t[i];
	}
	int k=0;
	for(int i=1;i<=m;i++){
		for(int j=0;j<=T;j++){
			if(t[i]>j){
				dp[i][j]=max(dp[i-1][j],dp[i][j]);
			}
			else{
				dp[i][j]=max(dp[i-1][j],dp[i][j]);
				dp[i][j]=max(dp[i][j],dp[i-1][j-t[i]]+c[i]);
			}
		}
	}
	cout<<T-dp[m][T];
	return 0; 
}
