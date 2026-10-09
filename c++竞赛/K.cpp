#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10;
ll n,m,l,A,B,a[N],b[N],c[N][2][2];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m>>l>>A>>B;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		cin>>b[i];
	}
	for(int i=2;i<=n;i++){
		if((a[i]-a[i-1])>A){
			cout<<"-1";
			return 0;
		}
	}
	for(int i=2;i<=m;i++){
		if((b[i]-b[i-1])>B){
			cout<<"-1";
			return 0;
		}
	}
	c[1][1][1]=1;
	c[1][2][1]=1;
	for(int i=2;i<=n;i++){
		ll num=a[i]-A-1;
		int pos=upper_bound(a+1,a+i+1,num)-a-1;
		c[i][1][1]=c[pos][1][1]+1;
	}
	cout<<c[n][1][1];
	return 0;
}

