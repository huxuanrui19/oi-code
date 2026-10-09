#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;
const int N=1e5+10;
namespace Mker
{
//  Powered By Kawashiro_Nitori
//  Made In Gensokyo, Nihon
	#define uint unsigned int
	uint sd;int op;
	inline void init() {scanf("%u %d", &sd, &op);}
	inline uint uint_rand()
	{
		sd ^= sd << 13;
		sd ^= sd >> 7;
		sd ^= sd << 11;
		return sd;
	}
	inline double get_n()
	{
		double x = (double) (uint_rand() % 100000) / 100000;
		return x + 4;
	}
	inline double get_k()
	{
		double x = (double) (uint_rand() % 100000) / 100000;
		return (x + 1) * 5;
	}
	inline void read(double &n,double &a, double &b)
	{
		n = get_n(); a = get_k();
		if (op) b = a;
		else b = get_k(); 
	}
}

int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);cout.tie(NULL);
	ll t;
	cin>>t;Mker::init();
	ld ans=0;
	while(t--){
		ld n,a,b;
		Mker::read(n,a,b);
		ll t=pow(n,a)+pow(n,b);
		ld x0=n,y0=pow(n,a)+pow(n,b),k=a*pow(n,a-1)+b*pow(n,b-1);
		ld nmax=(t+1-y0)/k+x0;
		ld nmin=(t-y0)/k+x0;
		ans+=nmax-nmin;
	}
	cout<<ans;
	return 0;
}

