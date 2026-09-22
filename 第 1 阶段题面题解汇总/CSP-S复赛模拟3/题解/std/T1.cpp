#include<bits/stdc++.h>
using namespace std;

const int N=1e6+5,M=1005;
int n,m,ans,nxt[N][26],f[M][M],t[100];
char a[N],b[M];

int main() {
	freopen("pair.in","r",stdin); 
	freopen("pair.out","w",stdout);
	scanf("%d%d%s%s",&m,&n,b+1,a+1);
	for(int i=0;i<=25;i++) t[i]=n+1;
	for(int i=n;i>=1;i--) {
		for(int j=0;j<=25;j++) {
			nxt[i][j]=t[j];
		}
		t[a[i]-'A']=i;
	}
	for(int j=0;j<=25;j++) {
		nxt[0][j]=t[j];
		nxt[n+1][j]=n+1;
	}
	for(int i=0;i<=m;i++) {
		for(int j=0;j<=m;j++) f[i][j]=n+1;
	}
	for(int i=1;i<=m;i++) {
		f[1][i]=min(nxt[0][b[i]-'A'],f[1][i-1]);
		if(f[1][i]!=n+1) ans=1;
	}
//	printf("%d %d\n",nxt[1][4],nxt[f[1][4]]
	for(int i=2;i<=m;i++) {
		for(int j=i;j<=m;j++) {
			f[i][j]=min(f[i][j-1],nxt[f[i-1][j-1]][b[j]-'A']);
			if(f[i][j]!=n+1) ans=i;
		//	printf("%d%c",f[i][j],j==m?'\n':' ');
		}
	}
	printf("%d\n",ans);
	return 0;
}
