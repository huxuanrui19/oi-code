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
#define cht 998244353
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
const int maxn = 5e5+5;
const int B = 131;
const i64 M = 998244353ll*1000000007;
char s[maxn],ans[maxn];vector<i64>G[maxn];i64 tot;
i64 k,n,mat[26][26],R[maxn],stk[maxn],fa[maxn],top;
IV dfs(i64 u){
	for(i64 v:G[u])
		dfs(v),ans[++tot]=v;
}
i64 nx[maxn],f[maxn][22],hsh[maxn][22],pw[maxn];
i64 Min(i64 x,i64 y){
	bool fg=0;i64 svx=x,svy=y;
	D(i,18,0)if(f[x][i]&&f[y][i]&&hsh[x][i]==hsh[y][i])
		x=f[x][i],y=f[y][i];
	return(s[x]<s[y]?svx:svy);
}
int main(){
	k=read();n=read();
	F(i,0,k-1)F(j,0,k-1)scanf("%1lld",&mat[i][j]);
	scanf("%s",s+1);F(i,1,n)s[i]-='a';
	pw[0]=B;F(i,1,18)pw[i]=__int128(pw[i-1])*pw[i-1]%M;
	stk[0]=n+1;
	D(i,n,1){
		while(top&&mat[s[i]][s[stk[top]]])
			fa[stk[top]]=i,G[i].push_back(stk[top--]);
		nx[i]=stk[top];
		stk[++top]=i;
	}
	D(i,n,1){

		i64 now=i+1;
		for(i64 v:G[i])
			if(v!=n+1)now=Min(now,f[v][0]);
		f[i][0]=now;

		hsh[i][0]=s[i]+1e6;
		F(j,1,18){
			f[i][j]=f[f[i][j-1]][j-1];
			hsh[i][j]=(__int128(hsh[i][j-1])*pw[j-1]+hsh[f[i][j-1]][j-1])%M;
		}
	}
	i64 now=1;
	while(now!=n+1)putchar(s[now]+'a'),now=f[now][0];
	return 0;
}