#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
const int N=5e4+10,M=20;
int n,q;
ll ans[N],sum[N],a[N];
ll LOG2[N],st_max[N][M],st_min[N][M];
void build(){
	LOG2[0]=-1;
	for(int i=1;i<N;i++) LOG2[i]=LOG2[i>>1]+1;
	int m=LOG2[n];
	for(int i=1;i<=n;i++) st_max[i][0]=st_min[i][0]=sum[i];
	for(int i=1;i<=m;i++){
		for(int j=1;(j+(1<<i)-1)<=n;j++){
			st_max[j][i]=max(st_max[j][i-1],st_max[j+(1<<(i-1))][i-1]);
			st_min[j][i]=min(st_min[j][i-1],st_min[j+(1<<(i-1))][i-1]);
		}
	}
}
ll max_query(int s,int t){
	int p=LOG2[t-s+1];
	return max(st_max[s][p],st_max[t-(1<<p)+1][p]);
}
ll min_query(int s,int t){
	int p=LOG2[t-s+1];
	return min(st_min[s][p],st_min[t-(1<<p)+1][p]);
}
int main(){
	//freopen("query.in","r",stdin);
	//freopen("query.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	build();
	cin>>q;
	while(q--){
		for(int i=1;i<=n;i++){
			ans[i]=-1e18;
		}
		int L,R;
		cin>>L>>R;
		for(int i=1;i<=n;i++){
			for(int j=max(i-R+1,1);j<=i;j++){
				ll num=-1e18;
				if((j+L-1)<=n) num=max_query(max(j+L-1,i),min(j+R-1,int(n)))-sum[j-1];
				ans[i]=max(ans[i],num);
			}
		}
		ull res=0;
		//for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
		//cout<<"\n";
		for(int i=1;i<=n;i++){
			res=res^(ull(ans[i]*i));
		}
		cout<<res<<"\n";
	}
	return 0;
}

