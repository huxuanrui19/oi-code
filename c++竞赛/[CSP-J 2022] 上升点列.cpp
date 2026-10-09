#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e2+10,K=1e2+10;
int dp[N][K];
struct point{
	int xi,yi;
	bool operator <(const point &tmp)const{
		if(xi!=tmp.xi) return xi<tmp.xi;
		else return yi<tmp.yi;
	}
}a[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i].xi>>a[i].yi;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		for(int j=0;j<=k;j++){
			dp[i][j]=1+j;
		}
	}
	for(int i=2;i<=n;i++){
		for(int t=i-1;t>=1;t--){
			if(a[t].xi>a[i].xi||a[t].yi>a[i].yi) continue;
			int dis=a[i].xi-a[t].xi+a[i].yi-a[t].yi-1;
			for(int j=dis;j<=k;j++){
				dp[i][j]=max(dp[i][j],dp[t][j-dis]+dis+1);
			}
		}
	}
	int maxn=-1;
	for(int i=1;i<=n;i++){
		maxn=max(maxn,dp[i][k]);
	}
	cout<<maxn;
	return 0;
}

