#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
template < typename T >
void read(T &x){
	x=0;int f=1;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f*=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=(x<<1)+(x<<3)+(ch&15);
		ch=getchar(); 
	}
	x*=f;
}
ll T,a,b,c;
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
	read(T);
	while(T--){
		read(a);read(b);read(c);
		if(c%__gcd(a,b)!=0){
			cout<<"-1\n";
		}
		else{
            ll cnt=__gcd(a,b);
            c/=cnt,a/=cnt,b/=cnt;
			ll x,y;
			ll d=exgcd(a,b,x,y);
			x*=c,y*=c;
			ll tmax=0,tmin=0;
			a/=d,b/=d;
			if(x%b==0) tmin=(-x)/b+1;
			else tmin=ceil(double(-x)/b);
			if(y%a==0) tmax=y/a-1;
			else tmax=floor(double(y)/a);
			if(tmin>tmax){
				ll xt=(x%b+b)%b,yt=(y%a+a)%a;
                if(xt==0) xt+=b;
                if(yt==0) yt+=a;
				cout<<xt<<" "<<yt<<"\n";
			}
			else{
				cout<<(tmax-tmin+1)<<" ";
				ll xt=x+b*tmin,yt=y-a*tmax;
				cout<<xt<<" "<<yt<<" ";
				xt=x+b*tmax,yt=y-a*tmin;
				cout<<xt<<" "<<yt<<"\n";
			}
		}
	}
	return 0;
}
