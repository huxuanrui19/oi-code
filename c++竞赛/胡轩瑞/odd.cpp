#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
ll a[N],sum[N];
int main(){
	freopen("odd.in","r",stdin);
	freopen("odd.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=(sum[i-1]+a[i])%2;
	}
	for(int i=1;i<=q;i++){
		ll l,r,k;
		cin>>l>>r>>k;
		if(((sum[l-1]+sum[n]-sum[r])%2+2+(((r-l+1)%2+2)*(k%2)%2))%2==1){
			cout<<"YES\n";
		}
		else{
			cout<<"NO\n";
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

