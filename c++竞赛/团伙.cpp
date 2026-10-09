#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e4+10;
int fa[N],em[N],b[N];
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
	for(int i=1;i<=n;i++){
		fa[i]=i;
		em[i]=0;
	}
	for(int i=1;i<=m;i++){
		char opt;
		int x,y;
		cin>>opt>>x>>y;
		if(opt=='F'){
			mer(x,y);
		}
		else{
			if(em[x]==0) em[x]=fi(y);
			else mer(em[x],y);
			if(em[y]==0) em[y]=fi(x);
			else mer(em[y],x);
		}
	}
	for(int i=1;i<=n;i++){
		b[fi(i)]++;
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		cnt+=(b[i]>=1);
	}
	cout<<cnt;
	return 0;
}

