#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
ll n,m,fa[N];
int find(int x){return (fa[x]==x)?x:(fa[x]=find(fa[x]));}
void merge(int u,int v){
	u=find(u);v=find(v);
	fa[u]=v;
}
void cle(){
	for(int i=1;i<=n;i++) fa[i]=i;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//freopen("theory.in","r",stdin);
	//freopen("theory.out","w",stdout);
	int t;cin>>t;
	while(t--){
		cin>>n>>m;cle();
		for(int i=1;i<=m;i++){
			int u,v;cin>>u>>v;
			merge(u,v);
		}
		ll x,y;x=y=0;
		for(int i=1;i<=n;i++){
			if(find(i)==find(1)) x++;
			else if(find(i)==find(n)) y++;
		}
		if(find(1)==find(n)) cout<<"Mr.Shi\n";
		else if(n%2==1){
			if((n*(n-1)/2-m)%2==0) cout<<"Mr.Shi\n";
			else cout<<"Mr.Xu\n";
		}else{
			if(x%2==y%2){
				if((n*(n-1)/2-m-x*y)%2==0) cout<<"Mr.Shi\n";
				else cout<<"Mr.Xu\n";
			}
			else cout<<"Mr.Xu\n";
		}
	}
	return 0;
}

