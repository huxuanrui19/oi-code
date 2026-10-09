#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int a[N],f[N][N];
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		f[i][i]=a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			f[i][j]=__gcd(f[i][j-1],f[j][j]);
		}
	}
	for(int i=1;i<=m;i++){
		int s,e;
		cin>>s>>e;
		cout<<f[s][e]<<endl;
	}
	return 0;
} 
