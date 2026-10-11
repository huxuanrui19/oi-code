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
const int maxn = 1e6+5;
const i64 oo = 1e18;
IV cmax(i64&x,i64 val){x<val?x=val,0:0;}
i64 n,m,A[maxn],B[maxn],S[maxn],T[maxn],P[maxn],Q[maxn],dp[maxn];
vector<i64>qwq[maxn];

i64 sum[maxn];

#define ls (o<<1)
#define rs (o<<1|1)
i64 mx[maxn*4],tag[maxn*4],add[maxn*4],cmx[maxn*4];
IV givet(i64 o,i64 v,i64 M){
	mx[o]=max(mx[o]+v,M);
	add[o]+=v;tag[o]+=v;tag[o]=max(tag[o],M);
}
IV pd(i64 o){
	givet(ls,add[o],tag[o]);
	givet(rs,add[o],tag[o]);
	add[o]=0;tag[o]=-oo;

	if(cmx[o]){
		cmx[ls]=cmx[rs]=1,cmx[o]=0;
		givet(rs,0,mx[ls]);
	}
}
IV upd(i64 o){
	mx[o]=max(mx[ls],mx[rs]);
}
IV Build(i64 o,i64 l,i64 r){
	cmx[o]=0;tag[o]=-oo;
	if(l==r){
		if(l==0)mx[o]=0;
		else mx[o]=-oo;
		return;
	}
	i64 mid=l+r>>1;
	Build(ls,l,mid);
	Build(rs,mid+1,r);
	upd(o);
}
IV M(i64 o,i64 l,i64 r,i64 x,i64 y,i64 v){
	if(x<=l&&r<=y)return givet(o,v,-oo);if(r<x||l>y)return;pd(o);
	i64 mid=l+r>>1;M(ls,l,mid,x,y,v);M(rs,mid+1,r,x,y,v);upd(o);
}
i64 Qr(i64 o,i64 l,i64 r,i64 p){
	if(l==r)return mx[o];i64 mid=l+r>>1;pd(o);
	return p<=mid?Qr(ls,l,mid,p):Qr(rs,mid+1,r,p);
}
int main(){
	// freopen("1.in","r",stdin);
	// freopen("1.out","w",stdout);
	n=read();m=read();
	F(i,1,n)A[i]=read(),S[i]=read(),P[i]=read();
	F(i,1,m)B[i]=read(),T[i]=read(),Q[i]=read();
	F(i,1,n)A[i]+=A[i-1];
	F(i,1,m)B[i]+=B[i-1];
	Build(1,0,m);
	// F(i,1,m)dp[i]=-1e18;
	// dp[0]=0;

	// (A[i]<=T[j]-B[j])
	F(j,1,m){
		M(1,0,m,j,m,-Q[j]);
		// F(x,j,m)dp[x]-=Q[j];
		i64 t=upper_bound(A,A+1+n,T[j]-B[j])-A;
		qwq[t].push_back(j);

		// A[i]<=T[j]-B[j];
	}
	F(i,0,n){
		for(i64 j:qwq[i]){
			M(1,0,m,j,m,Q[j]);
			// F(x,j,m)dp[x]+=Q[j];
		}
		cmx[1]=1;
		if(i!=n){
			i64 t=upper_bound(B,B+1+m,S[i+1]-A[i+1])-B-1;
			if(t>=0)M(1,0,m,0,t,P[i+1]);
			// F(j,0,m)M(1,0,m,j,j,(A[i+1]+B[j]<=S[i+1])*P[i+1]);
		}
	}
	for(i64 j:qwq[n+1]){
		M(1,0,m,j,m,Q[j]);
		// F(x,j,m)dp[x]+=Q[j];
	}


	cout<<Qr(1,0,m,m);
	return 0;
}//