#include<iostream>
using namespace std;
const int N=2000;
int t,n,m,k;
int C[2003][2003];//杨辉三角
int d[2003][2003];//前缀和
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);  
	cin>>t>>k;
	for(int i=0;i<=N;i++){
		for(int j=0;j<=i;j++){
			if(j==0||j==i)C[i][j]=1;
			else C[i][j]=(C[i-1][j-1]+C[i-1][j])%k;
		}
	}
	for(int i=0;i<=N;i++){
		for(int j=0;j<=N;j++){
			if(j<=i)d[i][j]=d[i-1][j]-d[i-1][j-1]+d[i][j-1]+(C[i][j]%k==0);//二维前缀和的式子
			else d[i][j]=d[i][i];//杨辉三角的空白部分要填充上
		}
	}
	while(t--){
		cin>>n>>m;
		cout<<d[n][min(n,m)]<<'\n';//答案
	}
	return 0;
}
