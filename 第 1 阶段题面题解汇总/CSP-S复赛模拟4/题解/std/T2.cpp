#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool memBeg;
const int maxn=2e5+5;
const int inf=0x3f3f3f3f;
int n,K,head[maxn],to[maxn<<1],nxt[maxn<<1],tot;
void add_edge(int u,int v) {
	to[tot]=v; nxt[tot]=head[u]; head[u]=tot++;
	to[tot]=u; nxt[tot]=head[v]; head[v]=tot++;
}
bool fruit[maxn];
int mid,minn[maxn][2];
void dfs(int root,int fa) {
	minn[root][0]=minn[root][1]=inf;
	int none=0,got=inf;
	for(int i=head[root];~i;i=nxt[i]) {
		if(to[i]==fa) continue;
		dfs(to[i],root);
		if(minn[to[i]][1]<inf)
			got=min(got,minn[to[i]][1]);
		else none=min(inf,none+minn[to[i]][0]);
	}
	if(fruit[root]) {
		if(none+1<=mid) {
			minn[root][1]=none+1;
			minn[root][0]=0;
		}
	} else {
		if(got+none+1<=mid) {
			minn[root][1]=got+none+1;
			minn[root][0]=0;
		} else if(none+1<=mid)
			minn[root][0]=none+1;
	}
//	printf("root = %d, minn_0 = %d, minn_1 = %d\n",root,minn[root][0],minn[root][1]);
}
bool memEn;
void fl() {
	freopen("orchard.in","r",stdin);
	freopen("orchard.out","w",stdout);
}
int main() {
	fprintf(stderr,"%.24lf\n",fabs(&memEn-&memBeg)/1024.0/1024.0);
	fl();
	scanf("%d%d",&n,&K);
	for(int i=1;i<=n;i++) head[i]=-1;
	for(int i=1;i<n;i++) {
		int u,v;
		scanf("%d%d",&u,&v);
		add_edge(u,v);
	}
	for(int i=1;i<=K;i++) {
		int x;
		scanf("%d",&x);
		fruit[x]=true;
	}
	int lo=1,hi=n;
	while(lo<hi) {
		mid=(lo+hi)>>1;
//		printf("mid = %d\n",mid);
		dfs(1,0);
		if(minn[1][1]<=mid)
			hi=mid;
		else lo=mid+1;
	}
	printf("%d\n",lo);
	return 0;
}
