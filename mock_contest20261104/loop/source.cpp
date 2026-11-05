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
#define her1 20081214
#define IV void
#define cht 998244353
#define ld long double
#define Aestas16 392699
#define ull unsigned long long
#define cp(x,y)memcpy(x,y,sizeof y)
#define mem(x,a)memset(x,a,sizeof x)
#define D(i,j,n)for(register int i=j;i>=n;i--)
#define E(i,now)for(register int i=first[now];i;i=e[i].nxt)
#define F(i,j,n)for(register int i=j;i<=n;i++)
#define DL(i,j,n)for(register i64 i=j;i>=n;i--)
#define EL(i,now)for(register i64 i=first[now];i;i=e[i].nxt)
#define FL(i,j,n)for(register i64 i=j;i<=n;i++)
//#define D(i,j,n)for(int i=j;i>=n;i--)
//#define E(i,now)for(int i=first[now];i;i=e[i].nxt)
//#define F(i,j,n)for(int i=j;i<=n;i++)
//#define DL(i,j,n)for(register ll i=j;i>=n;i--)
//#define EL(i,now)for(register ll i=first[now];i;i=e[i].nxt)
//#define FL(i,j,n)for(register ll i=j;i<=n;i++)
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
#undef ll
#include "assert.h"
mt19937_64 rnd(her1);
#include "functional"
using i64 = long long;
const int maxn = 2e6+5;
struct{i64 x,y;}pos[maxn];
i64 p[maxn],q[maxn],n,m,_[maxn],cnt[maxn*2];
IV add(i64 x,i64 v){for(;x<=n;x+=x&-x)_[x]+=v;}
i64 Q(i64 x){i64 ans=0;for(;x;x-=x&-x)ans+=_[x];return ans;}
int main(){
	freopen("loop.in","r",stdin);
    freopen("loop.out","w",stdout);
	n=read();m=read();
	F(i,1,n)pos[i].x=read(),pos[i].y=read(),p[i]=i;
	sort(pos+1,pos+n+1,[](auto x,auto y){return x.x<y.x;});
	sort(p+1,p+n+1,[](i64 x,i64 y){return pos[x].y<pos[y].y;});
	i64 ans=1e18,r=0,k=0,sum=0;
	D(i,n,1){
		r+=Q(p[i]),add(p[i],1),q[p[i]]=i;
		if(p[i]>i)k++,sum+=2*(p[i]-i),cnt[p[i]-i]++;
	}
	F(t,1,n){
		ans=min(ans,r-sum+k*(n-k));
		sum-=k*2,k-=cnt[t];i64 i=q[t];r+=n-i*2+1;
		if(n>i)k++,sum+=2*(n-i),++cnt[n-i+t];
	}
	cout<<ans;
	return 0;
}