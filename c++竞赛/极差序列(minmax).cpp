#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
ll n,m,a[N],d[N];
bool cmp(ll x,ll y) {return x>y;}
int main() {
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//freopen("minmax.in","r",stdin);
	//freopen("minmax.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=2;i<=n;i++) d[i-1]=a[i-1]-a[i];
	sort(d+1,d+n,cmp);
	for(int i=1;i<n;i++) d[i]+=d[i-1];
	for(int i=1;i<=m;i++){
		int op,x;
		cin>>op>>x;
		if(op==1) cout<<(a[1]-a[n]-d[x-1])<<"\n";
		else continue;
	}
	return 0;
}

