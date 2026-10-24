#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=19260817;
template < typename T >
void read(T &x){
	x=0;int f=1;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f*=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=(x<<1)+(x<<3)+(ch&15);
		x%=MOD;
		ch=getchar(); 
	}
	x*=f;
}
ll exgcd(ll a,ll b,ll &x,ll &y){
	if(b==0){
		x=1,y=0;
		return a;
	}
	ll xx,yy;
	ll d=exgcd(b,a%b,xx,yy);
	x=yy,y=xx-a/b*yy;
	return d;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll a,b;
	read(a);read(b);
	ll x,y;
	ll d=exgcd(b,MOD,x,y);
	if(a%d==0){
		cout<<((a/d*x)%MOD+MOD)%MOD;
	}
	else{
		cout<<"Angry!";
	}
	return 0;
}

