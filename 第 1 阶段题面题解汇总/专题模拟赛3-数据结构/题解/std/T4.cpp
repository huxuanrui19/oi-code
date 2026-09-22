#include<bits/stdc++.h>
#define ll long long
const int p=1e9+7;
using namespace std;

const int N=1e5+5,M=320;
int n,K,a[N],t[N],pre[N],bl[N],S,f[N],g[N],s[M][N],c[N];
int mo(int x) {
	return x>=p?x-p:x;
}
void ins(int x,int k) {
	s[bl[x]][0]=mo(s[bl[x]][0]+k);
	g[bl[x]]=mo(g[bl[x]]+k);
}
void add(int l,int r,int k) {
	if(bl[l]==bl[r]) {
		for(int i=l;i<=r;i++) {
			s[bl[i]][c[i]]=mo(s[bl[i]][c[i]]-f[i-1]+p);
			if(c[i]+t[bl[i]]<=K) g[bl[i]]=mo(g[bl[i]]-f[i-1]+p); 
			c[i]+=k; 
			s[bl[i]][c[i]]=mo(s[bl[i]][c[i]]+f[i-1]);
			if(c[i]+t[bl[i]]<=K) g[bl[i]]=mo(g[bl[i]]+f[i-1]);
		}
		return;
	}
	for(int i=bl[l]+1;i<=bl[r]-1;i++) {
	    if(k==1) { 
	    	int pos=K-t[i];
	        if(0<=pos&&pos<N) g[i]=mo(g[i]-s[i][pos]+p);
	        t[i]++;
	    } else {
	        t[i]--;
	        int pos=K-t[i];
	        if(0<=pos&&pos<N) g[i]=mo(g[i]+s[i][pos]);
	    }
	}
	for(int i=l;i<=S*bl[l];i++) {
		s[bl[i]][c[i]]=mo(s[bl[i]][c[i]]-f[i-1]+p);
		if(c[i]+t[bl[i]]<=K) g[bl[i]]=mo(g[bl[i]]-f[i-1]+p); 
		c[i]+=k; 
		s[bl[i]][c[i]]=mo(s[bl[i]][c[i]]+f[i-1]);
		if(c[i]+t[bl[i]]<=K) g[bl[i]]=mo(g[bl[i]]+f[i-1]);
	}
	for(int i=(bl[r]-1)*S+1;i<=r;i++) {
		s[bl[i]][c[i]]=mo(s[bl[i]][c[i]]-f[i-1]+p);
		if(c[i]+t[bl[i]]<=K) g[bl[i]]=mo(g[bl[i]]-f[i-1]+p); 
		c[i]+=k; 
		s[bl[i]][c[i]]=mo(s[bl[i]][c[i]]+f[i-1]);
		if(c[i]+t[bl[i]]<=K) g[bl[i]]=mo(g[bl[i]]+f[i-1]);
	}
}
int ask(int l,int r) {
	if(bl[l]==bl[r]) {
		int ret=0;
		for(int i=l;i<=r;i++) {
			if(t[bl[i]]+c[i]<=K) ret=mo(ret+f[i-1]);
		}
		return ret;
	}
	int ret=0;
	for(int i=bl[l]+1;i<=bl[r]-1;i++) {
		ret=mo(ret+g[i]);
	}
	for(int i=l;i<=S*bl[l];i++) {
		if(t[bl[i]]+c[i]<=K) ret=mo(ret+f[i-1]);
	}
	for(int i=(bl[r]-1)*S+1;i<=r;i++) {
		if(t[bl[i]]+c[i]<=K) ret=mo(ret+f[i-1]);
	}
	return ret;
}
int main() {
	freopen("isolate.in","r",stdin);
	freopen("isolate.out","w",stdout);	
	scanf("%d%d",&n,&K);
	for(int i=1;i<=n;i++) {
		scanf("%d",&a[i]);
		pre[i]=t[a[i]];
		t[a[i]]=i;
	}
	memset(t,0,sizeof(t));
	S=sqrt(n);
	for(int i=1;i<=n;i++) bl[i]=(i-1)/S+1;
	f[0]=1,ins(1,1);
	for(int i=1;i<=n;i++) {
		if(pre[i]) {
			add(pre[pre[i]]+1,pre[i],-1);
		}
		add(pre[i]+1,i,1);
		f[i]=ask(1,i); 
		ins(i+1,f[i]);
	//	printf("%d %d %d\n",g[2],t[2],c[4]);
	//	printf(" %d %d\n",i,f[i]);
	}
	printf("%d\n",f[n]);
	return 0;
}
