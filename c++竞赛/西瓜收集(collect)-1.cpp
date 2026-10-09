#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
struct node{
	int x,y;
	bool operator <(const node &tmp) const{
		if(x==tmp.x) return y<tmp.y;
		else return x<tmp.x;
	}
}pt[N];
int n,l[N],r[N];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>pt[i].x>>pt[i].y;
	}
	sort(pt+1,pt+n+1);
	l[0]=1e9+10;
	for(int i=1;i<=n;i++){
		l[i]=min(l[i-1],pt[i].y);
	}
	r[n+1]=-1e9-10;
	for(int i=n;i>=1;i--){
		r[i]=max(r[i+1],pt[i].y);
	}
	ll ans=0;
	for(int i=1;i<n;i++){
		if(l[i]>r[i+1]) ans++;
	}
	cout<<(ans+1);
	return 0;
}

