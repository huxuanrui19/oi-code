#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10;
ll n,k,a[N];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++) cin>>a[i];
		sort(a+1,a+n+1);
		int j=1,flag=0;ll ans=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1) flag=1;
			if(j==k&&a[i]==j) ans++;
			if(j<k&&a[i]>=j) ans+=a[i]-j,j++;
		}
		if(k==1&&flag==1) cout<<"-1\n";
		else if(k==1) cout<<"0\n";
		else if(j==k) cout<<ans<<"\n";
		else cout<<"-1\n";
	}
	return 0;
}