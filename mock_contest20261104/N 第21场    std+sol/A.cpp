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
const int maxn = 3e5+5;
i64 n,a[maxn],dp[maxn],sum[maxn];
int main(){
	freopen("arrange.in","r",stdin);
    freopen("arrange.out","w",stdout);
	n=read();
	F(i,1,n)a[i]=read();
	set<pair<i64,i64> >s;
	sum[0]=1;i64 res=0;
	F(i,1,n){
		pair<i64,i64>u;
		while(!s.empty()){
			u=(*s.rbegin());
			if(u.first>a[i]){
				res=(res-dp[u.second]+cht)%cht;
				s.erase(u);
			}
			else break;
		}
		if(s.empty())dp[i]=sum[i-1];
		else dp[i]=(res+sum[i-1]-sum[u.second])%cht;

		if(dp[i]<0)dp[i]=(dp[i]+cht);
		sum[i]=(sum[i-1]+dp[i])%cht;
		s.insert({a[i],i});res=(res+dp[i])%cht;
	}
	i64 ans=0;
	for(auto[x,y]:s)ans=(ans+dp[y])%cht;
	cout<<ans;
	return 0;
}