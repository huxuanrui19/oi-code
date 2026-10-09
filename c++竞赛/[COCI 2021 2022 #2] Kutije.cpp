#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e3+10;
int n,m,q,p[N][N],a[N][N];
int fa[N];
int find(int x){
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y){
	x=find(x);
	y=find(y);
	fa[x]=y;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			cin>>p[i][j];
			merge(j,p[i][j]);
		}
	}
	while(q--){
		int u,v;
		cin>>u>>v;
		if(find(u)==find(v)) cout<<"DA\n";
		else cout<<"NE\n";
	}
	return 0;
}

