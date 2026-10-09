#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e3+10;
ll n,m,all,sum[N][N],a[N][N];
bool check(ll x){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			sum[i][j]=0;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			sum[i][j]=sum[i][j-1]+sum[i-1][j]-sum[i-1][j-1]+(a[i][j]>=x);
		}
	}
	for(int i=x;i<=n;i++){
		for(int j=x;j<=m;j++){
			if((sum[i][j]-sum[i-x][j]-sum[i][j-x]+sum[i-x][j-x])==x*x){
				return 1;
			}
		}
	}
	return 0;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
			all+=a[i][j];
		}
	}
	ll l=0,r=min(n,m),ans=0;
	while(l<=r){
		ll mid=(l+r)>>1;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	cout<<all-ans*ans*ans;
	return 0;
}

