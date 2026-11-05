//when you use vector,pay attention to the size of val.
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
// #define I ll
#define her1 20081214
#define IV void
#define cht 998244353
#define ld long double
#define Aestas16 392699
#define ull unsigned long long
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
using i64 = long long;
const int maxd = 240+5;
const int maxn = 5e2+5;
const int maxm = 1e6+5;
IV cadd(i64&x,i64 val){x=(x+val)%cht;}
i64 gcd(i64 x,i64 y){return!y?x:gcd(y,x%y);}
i64 n,k,a[maxn][maxn],ni[maxm],cnt,trs[maxd][maxd],val[maxd],dp[maxn][maxn][maxd];
int main(){
	freopen("ground.in","r",stdin);
    freopen("ground.out","w",stdout);
	n=read();k=read();
	F(i,1,k)if(k%i==0)val[ni[i]=++cnt]=i;//cout<<cnt<<endl;
	F(i,1,n)F(j,1,n){
		a[i][j]=read();
		if(a[i][j]!=-1)a[i][j]=ni[gcd(a[i][j],k)];
	}
	F(i,1,cnt)F(j,1,cnt)trs[i][j]=ni[__gcd(val[i]*val[j],k)];
	dp[1][1][a[1][1]]=1;
	F(i,1,n)F(j,1,n)F(k,1,cnt){
		if(i<n&&a[i+1][j]!=-1)cadd(dp[i+1][j][trs[k][a[i+1][j]]],dp[i][j][k]);
		if(j<n&&a[i][j+1]!=-1)cadd(dp[i][j+1][trs[k][a[i][j+1]]],dp[i][j][k]);
	}
	return cout<<dp[n][n][ni[k]],0;
}