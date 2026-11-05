// #define G 3
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
const int maxn = 4e2+5;
const i64 oo = 1e18;

// bool vis[55][55][55][55];
char s[maxn][maxn];i64 vis[maxn][maxn];
i64 n,m,cur,L[maxn][maxn],R[maxn][maxn];
i64 dfs(i64 x,i64 y,i64 typ){
    if(vis[x][y]==-1)return oo;
    if(vis[x][y]||!x||!y||x>n||y>m)return 0;
    vis[x][y]=-1;i64 bk=2;
    if(typ==0){
        if(s[x][y]=='N'){
            bk+=dfs(x,y-1,0);
            bk+=dfs(x+1,y,s[x+1][y]=='N'?0:1);
        }
		else{
            bk+=dfs(x,y-1,0);
            bk+=dfs(x-1,y,s[x-1][y]=='N'?1:0);
        }
    }
	else{
        if(s[x][y]=='N'){
            bk+=dfs(x,y+1,1);
            bk+=dfs(x-1,y,s[x-1][y]=='N'?1:0);
        }
		else{
            bk+=dfs(x,y+1,1);
            bk+=dfs(x+1,y,s[x+1][y]=='N'?0:1);
        }
    }
    if(bk<oo)vis[x][y]=1;
    else bk=oo;

    return bk;
}

int main(){
	freopen("cake.in","r",stdin);
    freopen("cake.out","w",stdout);
	n=read();m=read();
	F(i,1,n)scanf("%s",s[i]+1);
	F(i,1,n){
		mem(vis,0);cur=0;
		F(j,1,m){
            L[i][j]=L[i][j-1]+dfs(i,j,0);
            if(L[i][j]>oo)L[i][j]=oo;
        }
		mem(vis,0);cur=0;
		D(j,m,1){
            R[i][j]=R[i][j+1]+dfs(i,j,1);
            if(R[i][j]>oo)R[i][j]=oo;
        }
		F(j,1,m){
			i64 ans=min(L[i][j],R[i][j]);
            if(ans<oo)printf("%lld ",ans);else printf("-1 ");
        }
		puts("");
	}
	return 0;
}