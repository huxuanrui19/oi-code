#include<bits/stdc++.h>
#include<stdint.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template<typename A,typename B>
// using htable=gp_hash_table<A,B>;
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define int long long
#define mod (998244353)
// int mod;
#ifndef ONLINE_JUDGE
#pragma GCC optimize(2)
#endif
using namespace std;
namespace IO{
	inline int read(){
		int n=0;
		int s=1;
		char x;
		while((x=getchar())<'0'||x>'9')
			if(x=='-')
				s=-1;
		while(x>='0'&&x<='9'){
			n=(n<<1)+(n<<3)+(x^48),
			x=getchar();
		}
		return n*s;
	}
	void write(char x){
		if(x)putchar(x);
	}
	void write(const char *x){
		for(;*x;++x)
			putchar(*x);
	}
	void write(char *x){
		for(;*x;++x)
			putchar(*x);
	}
	void write(signed x){
		if(x<0)putchar('-'),x=-x;
		if(x>9)write(x/10);
		putchar('0'+x-x/10*10);
	}
	void write(long long x){
		if(x<0)putchar('-'),x=-x;
		if(x>9)write(x/10);
		putchar('0'+x-x/10*10);
	}
	// void write(__int128 x){
	// 	if(x<0)putchar('-'),x=-x;
	// 	if(x>9)write(x/10);
	// 	putchar('0'+x-x/10*10);
	// }
	void write(double x){
		printf("%lf",x);
	}
	template<typename type1,typename type2,typename ...typen>
	void write(type1 a1,type2 a2,typen ...an){
		write(a1);
		write(a2,an...);
	}
}// namespace IO
inline long long max(long long a,long long b){return a>b?a:b;}
inline long long min(long long a,long long b){return a>b?b:a;}
inline signed max(signed a,signed b){return a>b?a:b;}
inline signed min(signed a,signed b){return a>b?b:a;}
class Frac{
	private:
		int a,b;
	public:
		Frac(){a=0,b=1;}
		Frac(int x,int y){assert(y!=0);if(y>0)a=x,b=y;else a=-x,b=-y;}
		Frac(int x){a=x,b=1;}
		Frac(Frac x,Frac y){*this=x/y;}
		bool operator==(Frac x){return x.a*b==a*x.b;}
		bool operator<(Frac x){return a*x.b<x.a*b;}
		bool operator>(Frac x){return a*x.b>x.a*b;}
		bool operator<=(Frac x){return a*x.b<=x.a*b;}
		bool operator>=(Frac x){return a*x.b>=x.a*b;}
		Frac operator-(){return Frac(-a,b);}
		Frac& operator+=(Frac x){return *this=Frac(a*x.b+x.a*b,b*x.b);}
		Frac& operator-=(Frac x){return *this=Frac(a*x.b-x.a*b,b*x.b);}
		Frac& operator*=(Frac x){return *this=Frac(a*x.a,b*x.b);}
		Frac& operator/=(Frac x){return *this=Frac(a*x.b,b*x.a);}
		Frac operator+(Frac x){return Frac(a*x.b+x.a*b,b*x.b);}
		Frac operator-(Frac x){return Frac(a*x.b-x.a*b,b*x.b);}
		Frac operator*(Frac x){return Frac(a*x.a,b*x.b);}
		Frac operator/(Frac x){return Frac(a*x.b,b*x.a);}
		void yf(){
			int g=__gcd(a,b);
			a/=g,b/=g;
		}
};
int pw(int a,int b){
	a%=mod;
	int ans=1;
	while(b){
		if(b&1)ans=1ll*ans*a%mod;
		a=1ll*a*a%mod;
		b>>=1;
	}
	return ans;
}
inline int lowbit(int i){return i&(-i);}
int bit(unsigned long long x,unsigned long long i){
	return (x&(1ull<<i))>>i;
}
inline int popc(int s){
	return __builtin_popcountll(s);
}
int gcd(int a,int b){return b==0?a:gcd(b,a%b);}
void wait(long double second){
	clock_t st=clock();
	while((long double)(clock()-st)/CLOCKS_PER_SEC<second);
}
// stop
int C[1001][1001];
int n,m,k,T;
int hav[101];
struct Node{
	int f[3][3];
	Node(){memset(f,0xcf,sizeof(f));f[0][0]=0;}
	bool operator<(Node x)const{for(int a=0;a<=2;a++)for(int b=0;b<=2;b++)if(f[a][b]!=x.f[a][b])return f[a][b]<x.f[a][b];return 0;}
	Node go(int x){
		if(f[0][0]==-1)return *this;
		Node ans;
		for(int a=0;a<=2;a++)for(int b=0;b<=2;b++)if(f[a][b]>=0){
			int res=f[a][b];
			int r=min(a,x);
			int vx=x-r;
			res+=r;
			for(int va=0;va<=b&&va<=vx;va++)for(int vb=0;vb+va<=vx&&vb<3;vb++)
				ans.f[va][vb]=max(ans.f[va][vb],res+(vx-va-vb)/3);
		}
		for(int i=0;i<=2;i++)for(int j=0;j<=2;j++)if(ans.f[i][j]>=k){
			ans=Node();
			ans.f[0][0]=-1;
			return ans;
		}
		return ans;
	}
	void display(){
		for(int i=0;i<3;i++)for(int j=0;j<3;j++)cout<<max(f[i][j],-1ll)<<" \n"[j==2];
		cout<<"\n";
	}
};
int to[2000][401];
int f[2][200][2000];
int cc;
map<Node,int>mapt;
void init(){
	Node st;
	cc++;
	mapt[st]=cc;
	queue<Node>que;
	que.push(st);
	st.f[0][0]=-1;
	mapt[st]=++cc;
	for(int i=0;i<=T+100;i++)to[cc][i]=cc;
	while(!que.empty()){
		Node x=que.front();
		// x.display();
		que.pop();
		for(int i=0;i<=T+100;i++){
			Node v=x.go(i);
			if(mapt[v]){to[mapt[x]][i]=mapt[v];continue;}
			mapt[v]=++cc;
			to[mapt[x]][i]=mapt[v];
			que.push(v);
		}
	}
	// cout<<cc<<"\n";
}
int ans[300];
int work(){
	T=192;
	init();
	f[0][0][1]=1;
	for(int i=1;i<=n;i++){
		int now=i&1,las=!now;
		memset(f[now],0,sizeof(f[now]));
		for(int mr=0;mr<=T;mr++)
			for(int j=1;j<=cc;j++)if(f[las][mr][j]){
				for(int x=hav[i];x-hav[i]+mr<=T;x++){
					int v=to[j][x];
					f[now][mr+x-hav[i]][v]=(f[las][mr][j]*C[mr+x-hav[i]][x-hav[i]]+f[now][mr+x-hav[i]][v])%mod;
					if(v==2)break;
					// if(i==2)break;
				}
			}
	}
	for(int i=0;i<=T;i++)for(int j=1;j<=cc;j++)if(j!=2)ans[i]=(ans[i]+f[n&1][i][j])%mod;
	// for(int j=0;j<=T;j++)for(int o=j+1;o<=T;o++)ans[o]=(ans[o]-ans[j]*pw(n,o-j)%mod+mod)%mod;
	int allans=0;
	for(int j=0;j<=T;j++)allans=(allans+ans[j]%mod*pw(pw(n,j),mod-2)%mod+mod)%mod;
	return allans;
}
signed main(){
	using namespace IO;
	string filename="mahjong";
	freopen((filename+".in").c_str(),"r",stdin);
	freopen((filename+".out").c_str(),"w",stdout);
	for(int i=0;i<=1000;i++){
		C[i][0]=C[i][i]=1;
		for(int j=1;j<i;j++)C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
	}
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++)hav[read()]++;
	write(work());
	return 0;
}

