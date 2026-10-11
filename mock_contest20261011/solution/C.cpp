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
#define ll int
using namespace std;
#define I ll
#define her1 19260817
#define cht 1000000007
#define IV void
#define ull unsigned long long
#define mem(x,cnt)memset(x,cnt,sizeof x)
#define F(i,j,n)for(register int i=j;i<=n;i++)
#define D(i,j,n)for(register int i=j;i>=n;i--)
#define E(i,now)for(register int i=first[now];i;i=e[i].nxt)
#define FL(i,j,n)for(register ll i=j;i<=n;i++)
#define DL(i,j,n)for(register ll i=j;i>=n;i--)
#define EL(i,now)for(register ll i=first[now];i;i=e[i].nxt)
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
#include "assert.h"
mt19937_64 rnd(her1);
const int maxn = 5e4+5;
ll n,q,L,a[maxn],ans[maxn*4];
IV cadd(ll&x,ll val){x=(x+val)%cht;}
struct node{ll id,l,r;};vector<node>V;
ll pre[maxn][21][21],suf[maxn][21][21],s1[maxn][21],s2[maxn][21];
IV cdq(ll l,ll r,vector<node>V){
	if(V.empty())return;
	if(l==r){for(auto[id,l,r]:V)ans[id]=1;return;}
	vector<node>ql,qr;ll mid=l+r>>1;
	mem(pre[mid+1],0);mem(suf[mid],0);
	D(i,mid,l){
		F(j,0,L)F(k,j,L)pre[i][j][k]=pre[i+1][j][k];cadd(pre[i][a[i]][a[i]],1);
		F(k,a[i],L)F(p,k,L)cadd(pre[i][a[i]][p],pre[i+1][k][p]);
	}
	F(i,mid+1,r){
		F(j,0,L)F(k,j,L)suf[i][j][k]=suf[i-1][j][k];cadd(suf[i][a[i]][a[i]],1);
		F(k,0,a[i])F(p,k,a[i])cadd(suf[i][k][a[i]],suf[i-1][k][p]);
	}
	F(i,l,mid)mem(s1[i],0);F(i,mid+1,r)mem(s2[i],0);
	F(i,l,mid)F(j,0,L)F(k,j,L)cadd(s1[i][k],pre[i][j][k]);
	F(i,mid+1,r)F(j,0,L)F(k,j,L)cadd(s2[i][j],suf[i][j][k]);
	for(auto w:V){
		if(w.r<=mid)ql.push_back(w);
		else if(w.l>mid)qr.push_back(w);
		else{
			F(i,1,L)F(j,i,L)cadd(ans[w.id],pre[w.l][i][j]);
			F(i,1,L)F(j,i,L)cadd(ans[w.id],suf[w.r][i][j]);
			F(j,0,L)F(k,j,L)cadd(ans[w.id],1ll*s1[w.l][j]*s2[w.r][k]%cht);
		}
	}
	cdq(l,mid,ql);cdq(mid+1,r,qr);
}
int main(){
	freopen("subseq.in","r",stdin);
    freopen("subseq.out","w",stdout);
	n=read();L=read();F(i,1,n)a[i]=read();q=read();
	F(i,1,q){ll l=read(),r=read();V.push_back({i,l,r});}
	cdq(1,n,V);F(i,1,q)printf("%d\n",(ans[i]+1)%cht);return 0;
}//