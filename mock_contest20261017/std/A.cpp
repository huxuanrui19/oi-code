#include<map>
#include<set>
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
#define cht 998244353
#define IV void
#define ull unsigned long long
#define mem(x,val) memset(x,val,sizeof x)
#define F(i,j,n)for(register int i=j;i<=n;i++)
#define D(i,j,n)for(register int i=j;i>=n;i--)
#define E(i,now)for(register int i=first[now];i;i=e[i].nxt)
#define FL(i,j,n)for(register i64 i=j;i<=n;i++)
#define DL(i,j,n)for(register i64 i=j;i>=n;i--)
#define EL(i,now)for(register i64 i=first[now];i;i=e[i].nxt)
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
#include "functional"
using i64 = long long;
mt19937_64 rnd((ull)(new char));
const int maxn = 2e5+5;
const i64 oo = 1e18;
i64 n,a[maxn],qwq[maxn],qc;
i64 calc(i64 l,i64 r){
	vector<i64>tmp;
	F(i,l,r)tmp.push_back(a[i]);
	sort(tmp.begin(),tmp.end());
	return tmp[tmp.size()/2];
}
priority_queue<i64>q1;
priority_queue<i64,vector<i64>,greater<i64> >q2;
i64 pre[maxn],suf[maxn];
int main(){
	freopen("median.in","r",stdin);
    freopen("median.out","w",stdout);
	n=read();
	F(i,1,n)a[i]=read();
	q1.push(a[1]);q2.push(oo);
	for(int i=1;i<=n;i+=2){
		while(q1.top()>q2.top()){
			i64 u=q1.top();q1.pop();
			i64 v=q2.top();q2.pop();
			q1.push(v);q2.push(u);
		}
		pre[i]=q1.top();
		// assert(pre[i]==calc(1,i));
		q1.push(a[i+1]);q2.push(a[i+2]);
	}
	while(q1.size())q1.pop();
	while(q2.size())q2.pop();
	q1.push(a[n]);q2.push(oo);
	for(int i=n;i>=1;i-=2){
		while(q1.top()>q2.top()){
			i64 u=q1.top();q1.pop();
			i64 v=q2.top();q2.pop();
			q1.push(v);q2.push(u);
		}
		suf[i]=q1.top();
		// assert(suf[i]==calc(i,n));
		q1.push(a[i-1]);q2.push(a[i-2]);
	}
	F(i,1,n)if((i&1)&&pre[i]==suf[i+1])
		return puts("Yes"),0;
	puts("No");
	return 0;
}