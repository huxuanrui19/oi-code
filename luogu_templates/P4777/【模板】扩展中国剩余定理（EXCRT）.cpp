#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128 lll;
const int N=1e5+10;
ll n,b[N],a[N];
lll gcd(lll a,lll b){return (!b) ? a : gcd(b,a%b);}
lll exgcd(lll a,lll b,lll &x,lll &y){
	if(!b){
		x=1,y=0;
		return a;
	}
	lll d=exgcd(b,a%b,y,x);
	y=y-(a/b)*x;
	return d;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>b[i];
	lll ai=1,bi=0,x,y;
	for(int i=1;i<=n;i++){
		if((b[i]-bi)%gcd(ai,a[i])!=0){cout<<"No solution\n";return 0;}
		else{
            lll gd=exgcd(ai,a[i],x,y);
			x=(bi-b[i])/gd*x;
			bi=bi-ai*x;
			ai=ai/gd*a[i];
            bi=(bi%ai+ai)%ai;
		}
	}
	cout<<(ll)((bi%ai+ai)%ai);
	return 0;
}
