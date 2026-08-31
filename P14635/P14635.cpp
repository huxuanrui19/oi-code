#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
ll n,m,lis[N]; 
struct node{
	ll x,y,tot;
	bool operator <(const node &tmp)const{
		return tot<tmp.tot;
	}
}c[N];
int main(){
	//freopen("candy.in","r",stdin);
	//freopen("candy.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>c[i].x>>c[i].y;
		c[i].tot=c[i].x+c[i].y;
		lis[i]=c[i].x;
	}
	sort(c+1,c+n+1);
	sort(lis+1,lis+n+1);
	for(int i=1;i<=n;i++) lis[i]=lis[i-1]+lis[i];
	ll ans=m/c[1].tot*2;
	for(int i=1;i<=n;i++){
        if(m>=lis[i]) ans=max(ans,i+(m-lis[i])/c[1].tot*2);
    }
	cout<<ans;
	return 0;
}
