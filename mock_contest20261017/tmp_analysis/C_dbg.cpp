#include<map>
#include<set>
#include<ctime>
#include<cmath>
#include<queue>
#include<bitset>
#include<cstdio>
#include<vector>
#include<random>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
#define I inline ll
#define her1 20090115
#define IV inline void
#define cht 1000000007
#define ld long double
#define Aestas16 392699
#define ull unsigned long long
#define mem(x,val)memset(x,val,sizeof x)
#define D(i,j,n)for(register int i=j;i>=n;i--)
#define E(i,now)for(register int i=first[now];i;i=e[i].nxt)
#define F(i,j,n)for(register int i=j;i<=n;i++)
#define DL(i,j,n)for(register ll i=j;i>=n;i--)
#define EL(i,now)for(register ll i=first[now];i;i=e[i].nxt)
#define FL(i,j,n)for(register ll i=j;i<=n;i++)
//#define D(i,j,n)for(int i=j;i>=n;i--)
//#define E(i,now)for(int i=first[now];i;i=e[i].nxt)
//#define F(i,j,n)for(int i=j;i<=n;i++)
//#define DL(i,j,n)for(ll i=j;i>=n;i--)
//#define EL(i,now)for(ll i=first[now];i;i=e[i].nxt)
//#define FL(i,j,n)for(ll i=j;i<=n;i++)
ll read(){
	ll ans=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')ans=ans*10+c-'0',c=getchar();
	return ans*f;
}
mt19937 rnd(her1);const int maxn = 2e5+5;
struct Pair{ll x,y;}a[maxn];ll dis[maxn],n,m,ans,u[maxn],v[maxn];vector<ll>g[maxn];
bool operator<(const Pair x,const Pair y){if(x.x+x.y!=y.x+y.y)return x.x+x.y<y.x+y.y;return x.x<y.x;}
const bool operator ==(const Pair x,const Pair y){return !(x<y)&&!(y<x);}
IV solve(){
	n=read();m=read();ans=0;
	F(i,0,2*n)dis[i]=0x3f3f3f3f,g[i].clear();
	F(i,1,m){
		u[i]=read();v[i]=read();
		g[u[i]].push_back(v[i]+n),g[v[i]+n].push_back(u[i]);
		g[u[i]+n].push_back(v[i]),g[v[i]].push_back(u[i]+n);
	}
	queue<ll>qwq;
	qwq.push(1),dis[1]=0;
	while(!qwq.empty()){
		ll x=qwq.front();qwq.pop();
		for(ll y:g[x])if(dis[y]>dis[x]+1)dis[y]=dis[x]+1,qwq.push(y);
	}
	if(dis[1+n]==0x3f3f3f3f)return cout<<n-1<<'\n',void();
	F(i,1,n)a[i]={min(dis[i],dis[i+n]),max(dis[i],dis[i+n])};
	sort(a+1,a+n+1);set<Pair>s;ll t=0;F(i,1,n){fprintf(stderr,"grp (%lld,%lld) ",a[i].x,a[i].y);
		ll j=i-1,flag=s.count({a[i].x-1,a[i].y-1});
		s.insert(a[i]);while(a[j+1]==a[i]&&j<n)j++;
		if(j-i+1>=t)ans+=(j-i+1)*(i>1),!flag&&(t=j-i+1);else ans+=t*(i>1),t=j-i+1;fprintf(stderr,"m=%lld flag=%lld -> t=%lld ans=%lld\n",j-i+1,flag,t,ans);
		if(j==n||a[j+1].x!=a[i].x+1||a[j+1].y!=a[i].y-1)
			ans+=(a[i].x+1!=a[i].y?t:t+1>>1),t=0;fprintf(stderr,"close diag, ans=%lld\n",ans);
		i=j;
	}
	printf("%lld\n",ans);
}
int main(){
ll T=read();while(T--)solve();return 0;}