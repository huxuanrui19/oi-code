#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128 lll;
const int N=1e5+10;
ll n,b[N],a[N];
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
	lll A=1,B=0;
	for(int i=1;i<=n;i++){
		if(0){cout<<"No solution\n";return 0;}
		else{
			lll x,y;
			lll gcd=exgcd(A,a[i],x,y);
			x=x*(B-b[i])/gcd;
			B=B-A*x;
			A=a[i]/gcd*A;
			B=(B%A+A)%A;
		}
	}
	cout<<(ll)((B%A+A)%A);
	return 0;
}

