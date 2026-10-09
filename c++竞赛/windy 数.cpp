#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=12;
ll a[N],dp[N][10];
void init(){
	for(int i=0;i<10;i++) dp[1][i]=1;
	for(int i=2;i<N;i++){
		for(int j=0;j<=9;j++){
			for(int k=0;k<=9;k++){
				if(abs(j-k)>=2) dp[i][j]+=dp[i-1][k];
			}
		}
	}
}
ll solve(ll x){
	if(!x) return 0;
	int cnt=0;
	while(x) a[++cnt]=x%10,x/=10;
	int res=0,last=-2;
	for(int i=cnt;i>=1;i--){
		int now=a[i];
		for(int j=(i==cnt);j<now;j++){
			if(abs(last-j)>=2) res+=dp[i][j];
		}
		if(abs(now-last)<2) break;
		last=now;
		if(i==1) res++;
	}
	for(int i=1;i<cnt;i++){
		for(int j=1;j<=9;j++){
			res+=dp[i][j];
		}
	}
	return res;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
	int a,b;
	cin>>a>>b;
	cout<<solve(b)-solve(a-1);
	return 0;
}

