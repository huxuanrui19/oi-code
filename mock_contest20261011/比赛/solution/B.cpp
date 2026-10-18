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
const int maxn = 2e3+5;
const i64 oo = 1e18;
struct node{i64 u,v,w;};bool vis[maxn];
IV cmin(i64&x,i64 val){x>val?x=val,0:0;}
i64 n,m,u[maxn],v[maxn],l[maxn],c[maxn],fa[maxn],Ans;
i64 find(i64 x){return fa[x]==x?x:fa[x]=find(fa[x]);}
i64 dis[maxn];pair<i64,i64>mn[maxn*2];
IV upd(i64 p,i64 v){
	// cerr<<"upd"<<p<<' '<<v<<endl;
	mn[p+=n-1].first=v;
	while(p>>=1)mn[p]=min(mn[p<<1],mn[p<<1|1]);
}
vector<pair<i64,i64> >G[maxn];
i64 getdis(i64 s,i64 t){
	F(i,1,n)dis[i]=oo,vis[i]=0;
	F(i,n,2*n-1)mn[i]=make_pair(oo,i-(n-1));
	D(i,n-1,1)mn[i]=min(mn[i<<1],mn[i<<1|1]);
	upd(s,0);dis[s]=0;
	while(mn[1].first<oo){
		i64 u=mn[1].second;vis[u]=1;
		// cerr<<u<<' '<<mn[1].first<<endl;
		upd(u,oo);
		for(auto[v,w]:G[u])if(!vis[v]&&dis[u]+w<dis[v])
			upd(v,dis[v]=dis[u]+w);
	}
	// cout<<s<<' '<<t<<' '<<dis[t]<<endl;
	return dis[t];
}
bool ve[maxn];
int main(){
	freopen("upkeep.in","r",stdin);
    freopen("upkeep.out","w",stdout);
	n=read();m=read();i64 cnt=0;
	vector<node>e0;F(i,1,n)fa[i]=i;
	F(i,1,m){
		u[i]=read(),v[i]=read(),l[i]=read(),c[i]=read();
		if(!l[i])e0.push_back({u[i],v[i],c[i]}),ve[i]=1;else cnt++;
	}
	sort(e0.begin(),e0.end(),[](node A,node B){
		return A.w<B.w;
	});	
	for(auto[u,v,w]:e0){
		i64 fu=find(u),fv=find(v);
		if(fu==fv)continue;fa[fu]=fv;Ans+=w;
	}
	F(_,1,cnt){
		i64 pos=0;
		F(i,1,m)if(!ve[i]){
			if(!pos)pos=i;
			else if(l[i]<l[pos])pos=i;
			else if(l[i]==l[pos]&&c[i]<c[pos])pos=i;
		}
		ve[pos]=1;
		i64 nu=find(u[pos]),nv=find(v[pos]);
		if(l[pos]<getdis(nu,nv)){
			// cout<<"add"<<nu<<' '<<nv<<' '<<l[pos]<<endl;
			G[nu].push_back({nv,l[pos]});
			G[nv].push_back({nu,l[pos]});
			Ans+=c[pos];
		}
	}
	cout<<Ans;
	return 0;
}