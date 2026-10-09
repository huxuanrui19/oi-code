#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
ll a,b,x,y;
ll exgcd(ll a,ll b,ll &x,ll &y){
	if(!b){
		x=1,y=0;
		return a;
	}
	ll d=exgcd(b,a%b,y,x);
	y=y-(a/b)*x;
	return d;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>a>>b;
	exgcd(a,b,x,y);
	x=(x%b+b)%b;
	cout<<x;
	return 0;
}

