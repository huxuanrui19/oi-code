#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=250+10;
const ll inf=1e18;
ll n,num,w[3][N],rk[3][N],pos[3][N],dp[N][N][N];
bool cmp(int x,int y){
	return w[num][x]<w[num][y];
}
int main() {
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){cin>>w[0][i]>>w[1][i]>>w[2][i];}
	for(num=0;num<=2;num++){
		for(int i=1;i<=n;i++) pos[num][i]=i;
		sort(pos[num]+1,pos[num]+n+1,cmp);
		for(int i=1;i<=n;i++) rk[num][pos[num][i]]=i;
	}
	for(int a=0;a<=n;a++){
		for(int b=0;b<=n;b++){
			for(int c=0;c<=n;c++){
				dp[a][b][c]=inf;
			}
		}
	}
	dp[0][0][0]=0;
	for(int a=0;a<=n;a++){
		for(int b=0;b<=n;b++){
			for(int c=0;c<=n;c++){
				if(dp[a][b][c]!=inf){
					if(a!=n){
						int p=pos[0][a+1];
						if(rk[1][p]<=b&&rk[2][p]<=c){
							dp[a+1][b][c]=min(dp[a+1][b][c],dp[a][b][c]+w[1][pos[1][b]]+w[2][pos[2][c]]-w[1][p]-w[2][p]);
						}
						else{
							dp[a+1][b][c]=min(dp[a+1][b][c],dp[a][b][c]);
						}
					}
					if(b!=n){
						int p=pos[1][b+1];
						if(rk[0][p]<=a&&rk[2][p]<=c){
							dp[a][b+1][c]=min(dp[a][b+1][c],dp[a][b][c]+w[0][pos[0][a]]+w[2][pos[2][c]]-w[0][p]-w[2][p]);
						}
						else{
							dp[a][b+1][c]=min(dp[a][b+1][c],dp[a][b][c]);
						}
					}
					if(c!=n){
						int p=pos[2][c+1];
						if(rk[1][p]<=b&&rk[0][p]<=a){
							dp[a][b][c+1]=min(dp[a][b][c+1],dp[a][b][c]+w[1][pos[1][b]]+w[0][pos[0][a]]-w[1][p]-w[0][p]);
						}
						else{
							dp[a][b][c+1]=min(dp[a][b][c+1],dp[a][b][c]);
						}
					}
				}
			}
		}
	}
	cout<<dp[n][n][n];
	return 0;
}
