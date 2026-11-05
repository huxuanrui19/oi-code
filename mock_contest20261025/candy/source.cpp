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
#define E(i,now)for(register int i=firssgt[now];i;i=G[i].nxt)
#define F(i,j,n)for(register int i=j;i<=n;i++)
#define DL(i,j,n)for(register i64 i=j;i>=n;i--)
#define EL(i,now)for(register i64 i=firssgt[now];i;i=G[i].nxt)
#define FL(i,j,n)for(register i64 i=j;i<=n;i++)
//#define D(i,j,n)for(int i=j;i>=n;i--)
//#define E(i,now)for(int i=firssgt[now];i;i=G[i].nxt)
//#define F(i,j,n)for(int i=j;i<=n;i++)
//#define DL(i,j,n)for(register ll i=j;i>=n;i--)
//#define EL(i,now)for(register ll i=firssgt[now];i;i=G[i].nxt)
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
using i64 = int;
#include "assert.h"
mt19937_64 rnd(her1);
#include "functional"
const i64 oo = 1e9;
const int maxn = 2e6+5;
priority_queue<i64>qwq;
i64 n,a[maxn],Mn[maxn],S;
IV cmin(i64&x,i64 val){x>val?x=val,0:0;}
int main(){
	freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
	n=read();
	F(i,1,n)S+=max(a[i]=read(),0);
	F(i,1,n){Mn[i]=oo;if(a[i]==-1)Mn[i]=0;}
	F(i,2,n)cmin(Mn[i],Mn[i-1]+1);
	D(i,n-1,1)cmin(Mn[i],Mn[i+1]+1);
	i64 flag=0,ans=0,sum=0,X=0;
	F(i,1,n){
		cmin(X,Mn[i]);if(!a[i])continue;
		if(a[i]==-1){if(flag)ans++,flag=0;continue;}
		if(flag){
			swap(X,Mn[i]);
			if((Mn[i]+sum)*2<=i-1)
				sum+=Mn[i],qwq.push(Mn[i]),++ans,flag=0;
			else if(!qwq.empty()&&Mn[i]<=qwq.top()){
				i64 xx=qwq.top();
				ans--;sum-=qwq.top();qwq.pop();
				sum+=Mn[i];qwq.push(Mn[i]);ans++;Mn[i]=xx;
			}
			swap(X,Mn[i]);
		}
		F(j,1,a[i]-1){
			if((Mn[i]+sum)*2<=i-1)sum+=Mn[i],qwq.push(Mn[i]),++ans;
			else if(!qwq.empty()&&Mn[i]<=qwq.top()){
				ans--;sum-=qwq.top(),flag=1,X=qwq.top(),qwq.pop();
				sum+=Mn[i],qwq.push(Mn[i]),++ans;
			}
			else break;
		}
		!flag?flag=1,X=Mn[i]:(cmin(X,Mn[i]),0);
	}
	return cout<<S-ans-flag,0;
}