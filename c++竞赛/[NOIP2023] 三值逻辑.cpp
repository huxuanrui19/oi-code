#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
int fa[N*2+4],val[N*2+4];
int find(int x){
	if(x==fa[x]) return x;
	else return fa[x]=find(fa[x]);
}
void merge(int x,int y){
	x=find(x);y=find(y);
	fa[x]=y;
}
int main(){
	int c,q;
	cin>>c>>q;
	while(q--){
		int n,m;
		cin>>n>>m;
		for(int i=1;i<=2*n+4;i++) fa[i]=i;
		for(int i=1;i<=2*n+4;i++) val[i]=i;
		for(int i=1;i<=m;i++){
			char op;
			cin>>op;
			int x;
			cin>>x;
			if(op=='T'){
				val[x]=n+1;
				val[x+n]=n*2+3;
			}
			else if(op=='F'){
				val[x]=n*2+3;
				val[x+n]=n+1;
			}
			else if(op=='U'){
				val[x]=n+2;
				val[n+x]=2*n+4;
			}
			else if(op=='+'){
				int y;
				cin>>y;
				val[x]=y;
				val[x+n]=val[y+n];
			}
			else{
				int y;
				cin>>y;
				val[x]=y+n;
				val[x+n]=y;
			}
			
		}
		for(int i=1;i<=2*n+4;i++) cout<<val[i]<<" ";
		cout<<endl;
		for(int i=1;i<=2*n+4;i++){
			merge(i,val[i]);
		}
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(find(i)==find(i<=n+2?i+n+2:i-n-2)) cnt++;
		}
		cout<<cnt<<endl;
	}
	return 0;
} 
