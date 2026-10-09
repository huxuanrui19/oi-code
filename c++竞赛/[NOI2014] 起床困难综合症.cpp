#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
int cnt0=0,cnt1=-1,a[N][2];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		string op;
		ll x;
		cin>>op>>x;
		if(op[0]=='A'){
			cnt0&=x;
			cnt1&=x;
		}
		else if(op[0]=='O'){
			cnt0|=x;
			cnt1|=x;
		}
		else{
			cnt0^=x;
			cnt1^=x;
		}
	}
	for(int i=0;i<=30;i++){
		a[i][0]=cnt0&(1<<i);
		a[i][1]=cnt1&(1<<i);
	}
	ll maxn=0;
	for(int i=30;i>=0;i--){
		if(a[i][0]!=0) maxn|=(1<<i);
		else if(a[i][1]!=0&&m>=(1<<i)){
			m-=(1<<i);
			maxn|=(1<<i);
		}
	}
	cout<<maxn;
	return 0;
}
