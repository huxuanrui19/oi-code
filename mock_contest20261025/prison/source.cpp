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
#define mem(x,val)memset(x,val,sizeof x)
#define D(i,j,n)for(register int i=j;i>=n;i--)
#define E(i,now)for(register int i=first[now];i;i=G[i].nxt)
#define F(i,j,n)for(register int i=j;i<=n;i++)
#define DL(i,j,n)for(register i64 i=j;i>=n;i--)
#define EL(i,now)for(register i64 i=first[now];i;i=G[i].nxt)
#define FL(i,j,n)for(register i64 i=j;i<=n;i++)
//#define D(i,j,n)for(int i=j;i>=n;i--)
//#define E(i,now)for(int i=first[now];i;i=G[i].nxt)
//#define F(i,j,n)for(int i=j;i<=n;i++)
//#define DL(i,j,n)for(register ll i=j;i>=n;i--)
//#define EL(i,now)for(register ll i=first[now];i;i=G[i].nxt)
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
const int maxn = 2e6+5;vector<i64>g[maxn];
i64 n,d,m,p,k,t[maxn],s[maxn],w[maxn],a[maxn];
IV dfs(i64 u){
	i64 x=0;for(i64 v:g[u])dfs(v),w[x]<w[v]?x=v,0:0;
	w[u]+=w[x];for(i64 v:g[u])if(v^x)a[++k]=w[v];
}
int main(){
freopen("prison.in","r",stdin);
    freopen("prison.out","w",stdout);
	n=read();d=read();m=read();
	F(i,1,n)t[i]=read();s[++p]=n+1;
	D(i,n,1){
		if(t[i]<=m)for(;p>1&&t[i]+s[p]-i<=m;p--)
			w[s[p]]=1,g[s[p-1]].push_back(s[p]);
		else s[++p]=i;
	}
	i64 ans=p-1;while(p)g[0].push_back(s[p--]);
	dfs(0);a[++k]=w[0];nth_element(a+1,a+d,a+k+1,greater<i64>());
	F(i,1,d)ans+=a[i];return cout<<n-ans,0;
}