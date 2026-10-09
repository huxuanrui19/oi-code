#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
struct node{
	int x,y;
	bool operator <(const node &tmp)const{
		if(x==tmp.x) return y<tmp.y;
		else return x<tmp.x;
	}
}pt[N];
int n,minn[N],maxn[N];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>pt[i].x>>pt[i].y;
	sort(pt+1,pt+n+1);
	minn[0]=1e9+10;
	for(int i=1;i<=n;i++) minn[i]=min(minn[i-1],pt[i].y);
	maxn[n+1]=-1e9-10;
	for(int i=n;i>=1;i--) maxn[i]=max(maxn[i+1],pt[i].y);
	int ans=0;
	for(int i=1;i<n;i++){
		if(minn[i]>maxn[i+1]) ans++;
	}
	cout<<ans+1;
	return 0;
}

