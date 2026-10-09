#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
int c[N],pos[N],sum[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	ll m,n,t,k,r;
	cin>>m>>n>>t>>k>>r;
	for(int i=1;i<=t;i++){
		cin>>c[i];
		pos[c[i]]=1;
	}
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+pos[i];
	}
	ll ans=0,cnt=0;
	for(int i=1;i<=m-k+1;i++){
		int j=i+k-1;
		if(i<=r&&j>=r){
			cnt++;
		}
	}
    //cout<<cnt<<endl;
	if(k%2==0){
		for(int i=k;i<=n;i++){
			if((sum[i]-sum[i-k])%2==1){
				ans+=cnt;
			}
		}
	}
	else{
        ll tot=(n-k+1)*(m-k+1);
		for(int i=k;i<=n;i++){
			if((sum[i]-sum[i-k])%2==1){
				ans+=cnt;
			}
		}
        ans=tot-ans;
	}
	cout<<ans;
	return 0;
}
