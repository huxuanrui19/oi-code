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
#define I ll
#define her1 20081214
#define IV void
#define cht 1000000007
#define ld long double
#define Aestas16 392699
#define ull unsigned long long
#define cp(x,y)memcpy(x,y,sizeof y)
#define mem(x,val)memset(x,val,sizeof x)
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
const int maxn = 1e6+5;

// #define Q(x) lo
i64 n,k,a[maxn],ans=1e9,mx,b[maxn],tot;
struct BIT{
	i64 c[maxn],ans;IV clr(){F(i,1,n)c[i]=0;}
	IV add(i64 p,i64 v){for(;p<=n;p+=p&-p)c[p]+=v;}
	i64 Q(i64 p){ans=0;for(;p;p-=p&-p)ans+=c[p];return ans;}
}bit;
int main(){
	n=read();k=read();
	F(i,1,n)a[i]=read(),mx=max(mx,a[i]);

	F(i,1,n)if(a[i])b[++tot]=a[i];
	sort(b+1,b+1+tot);tot=unique(b+1,b+1+tot)-b-1;
	F(i,1,n)a[i]=upper_bound(b+1,b+1+tot,a[i])-b-1;
	// F(i,1,n)cout<<a[i]<<' ';puts("");
	auto check=[&](i64 M)->bool{
		bit.clr();
		priority_queue<i64>qwq;
		i64 cnt=0,now=0;
		static i64 R[maxn],nd[maxn];
		F(i,1,n)cnt+=(!a[i]);
		// F(i,1,n)cout<<b[i]<<' ';puts("");
		F(i,1,cnt)nd[i]=0;
		D(i,n,1){
			bit.add(a[i]+1,1);
			// cout<<i<<' '<<bit.Q(a[i])-M<<endl;
			R[i]=max(bit.Q(a[i])-M,0ll);
		}
		F(i,1,n){
			if(!a[i])now++;
			if(a[i]){
				i64 r=cnt-R[i]+1;
				// cout<<R[i]<<' '<<i<<' '<<r<<' '<<a[i]<<endl;
				if(r<=now)return 0;
				nd[r]=max(nd[r],a[i]);
			}
		}
		F(i,1,cnt)nd[i]=max(nd[i],nd[i-1]);
		// F(i,1,cnt)cout<<nd[i]<<' ';puts("");
		i64 S=0;
		F(i,1,cnt)S+=b[nd[i]];
		// cout<<S<<endl;
		return S<=k;
	};
	// cout<<check(0)<<endl;

	i64 now=-1;
	D(i,30,0)if(now+(1<<i)<=n&&!check(now+(1<<i)))
		now+=(1<<i);
	cout<<now+1;
	return 0;
}//0.31