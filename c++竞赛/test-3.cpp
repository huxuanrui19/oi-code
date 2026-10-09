#include <cstdio>

const int N=1e5+5;
int n,tot,p[N],f[N];
bool flg[N];

void sieve(int n) {
	f[1]=1;
	for(int i=2;i<=n;++i) {
		if(!flg[i]) p[++tot]=i,f[i]=f[i-1];
		for(int j=1;j<=tot&&i*p[j]<=n;++j) {
			flg[i*p[j]]=1,f[i*p[j]]=f[i]+f[p[j]];
			if(i%p[j]==0) break;
		}
	}
}
int main() {
	sieve(N-5);
	int T;
	for(scanf("%d",&T);T--;) {
		scanf("%d",&n);
		long long ans=0,flg=0;
		for(int i=1;i<=n;++i) {
			int p,c;
			scanf("%d%d",&p,&c);
			if(p==2) flg=1;
			ans+=1LL*f[p]*c;
		}
		if(!flg) ++ans;
		printf("%lld\n",ans);
	}
	return 0;
}
