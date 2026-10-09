#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e3+10;
const ll mod=1e8;
string a,b;
int n,m,f[2][N],g[2][N];
int main(){
	//freopen("lcs.in","r",stdin);
	//freopen("lcs.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>a>>b;
	n=a.size();m=b.size();
	a=' '+a;
	b=' '+b; 
    n--;m--;
	for(int i=0;i<=1;i++) g[i][0]=1;
	for(int j=0;j<=m;j++) g[0][j]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
            int cur=i%2,pre=(i-1)%2;
			f[cur][j]=max(f[cur][j-1],f[pre][j]);
			int flag=1;
			if(a[i]==b[j]&&f[pre][j-1]+1>=f[cur][j]){
				flag=0;
				f[cur][j]=f[pre][j-1]+1;
				g[cur][j]=g[pre][j-1];
			}
			if(f[cur][j]==f[pre][j]) g[cur][j]=(g[cur][j]+g[pre][j])%mod;
			if(f[cur][j]==f[cur][j-1]) g[cur][j]=(g[cur][j]+g[cur][j-1])%mod;
			if(flag&&f[pre][j-1]==f[pre][j]&&f[pre][j-1]==f[cur][j-1]){
				g[cur][j]=((g[cur][j]-g[pre][j-1])%mod+mod)%mod;
			}
		}
	}
	cout<<f[n%2][m]<<"\n"<<g[n%2][m];
	return 0;
}

