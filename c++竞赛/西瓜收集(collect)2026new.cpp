#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
struct node{
	ll x,y;
	bool operator <(const node &tmp) const{
		if(x!=tmp.x) return x<tmp.x;
		else return y<tmp.y;
	}
}a[N];
ll n,l[N],r[N];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i].x>>a[i].y;
	sort(a+1,a+n+1);
	l[0]=1e18;
	for(int i=1;i<=n;i++) l[i]=min(l[i-1],a[i].y);
	r[n+1]=-1e18;
	for(int i=n;i>=1;i--) r[i]=max(r[i+1],a[i].y);
	ll ans=0;
	for(int i=1;i<=n;i++){
		if(l[i]>r[i+1]) ans++; 
	}
	cout<<ans;
	return 0;
}
