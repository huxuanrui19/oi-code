#include<bits/stdc++.h>
using namespace std;
const int N=2e3+5;
int n,m,k,c[N][N],sum[N][N];
void init(){
	c[0][0]=c[1][0]=c[1][1]=1;
	for(int i=2;i<N;i++){
		c[i][0]=1;
		for(int j=1;j<=i;j++){
			c[i][j]=(c[i-1][j]+c[i-1][j-1])%k;
			sum[i][j]=sum[i][j-1]+sum[i-1][j]-sum[i-1][j-1]+(c[i][j]==0);
		}
		sum[i][i+1]=sum[i][i];
	}
}
int main(){
	int t;
	cin>>t>>k;
	init();
	while(t--){
		cin>>n>>m;
		cout<<sum[n][min(n,m)]<<endl;
	}
}
