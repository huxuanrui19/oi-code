#include<bits/stdc++.h>
using namespace std;
typedef __int128 ll;
const int N=1e5+10;
__int128 read()
{
	__int128 x=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')	w=-w;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	return w*x;
}

void write(__int128 x)
{
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
	if(x>9)	write(x/10);
	putchar(x%10+'0');
}

ll gcd(ll a,ll b){
    if(!b) return a;
    return gcd(b,a%b);
}
ll lcm(ll a,ll b){
    return a/gcd(a,b)*b;
}
int main()
{
	int t;
	cin>>t;
	while(t--){
		ll n,a,b,c;
		n=read();a=read();b=read();c=read();
		write(n/c-n/lcm(a,c)+n/a-n/lcm(a,b)+n/lcm(lcm(a,b),c));
		cout<<"\n";
	}
	return 0;
}
