#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e4+10;
int fa[N*2];
int fi(int s){
	if(s!=fa[s]) return fa[s]=fi(fa[s]);
	return s;
}
void mer(int x,int y){
	x=fi(x);
	y=fi(y);
	if(x!=y) fa[x]=y; 
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=2*n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		char opt;
		int x,y;
		cin>>opt>>x>>y;
		if(opt=='F'){
			mer(x,y);
		}
		else{
			mer(y+n,x);
			mer(x+n,y);
		}
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(fa[i]==i) cnt++; 
	}
	cout<<cnt;
	return 0;
}

