#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int n,q;
int fa[maxn][18];
struct node{
	int mn,mx;
}g[maxn];
int gf(int x,int c){
	if(x==fa[x][c])return x;
	return fa[x][c]=gf(fa[x][c],c);
}
void merge(int l,int r,int k){
	if(k<0)return ;
	if(gf(l,k)==gf(r,k))return ;
	if(k>0){
		fa[gf(l,k)][k]=gf(r,k);	
	}
	else{
		g[gf(r,k)].mn=min(g[gf(l,k)].mn,g[gf(r,k)].mn);
		g[gf(r,k)].mx=max(g[gf(l,k)].mx,g[gf(r,k)].mx);
		fa[gf(l,k)][k]=gf(r,k);
	}
	merge(l,r,k-1);
	merge(l+(1<<(k-1)),r+(1<<(k-1)),k-1);
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>q;
	for(int s=0;s<=17;s++)
		for(int i=1;i<=n;i++)
			fa[i][s]=i;
	for(int i=1;i<=n;i++)g[i]={i,i};
	for(int i=1;i<=q;i++){
		int op,x,l,r,len;
		cin>>op;
		if(op==1){
			cin>>x;
			cout<<g[gf(x,0)].mn<<" "<<g[gf(x,0)].mx<<"\n";
		}else{
			cin>>l>>r>>len;
			for(int j=17;j>=0;j--){
				if(len>>j&1)
					merge(l,r,j),l+=(1<<j),r+=(1<<j);
			} 
		}
	}
	return 0;
}
