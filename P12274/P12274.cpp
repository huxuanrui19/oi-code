#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3e5+10;
int n,m,fa[N],rk[N];
struct op{
	int xrk,yrk,xroot,yroot;
};
stack<op> st;
void init(){
	for(int i=1;i<=n;i++) fa[i]=i,rk[i]=1;
}
int find(int x){return (x==fa[x])?x:find(fa[x]);};
void merge(int x,int y){
	if(find(x)==find(y)) st.push((op){-1,-1,-1,-1});
	else{
		int xrt=find(x),yrt=find(y);
		if(rk[xrt]<rk[yrt]){
			fa[xrt]=yrt;
			st.push((op){rk[xrt],rk[yrt],xrt,yrt});
		}
		else{
			fa[yrt]=xrt;
			st.push((op){rk[yrt],rk[xrt],yrt,xrt});
			if(rk[xrt]==rk[yrt]) rk[xrt]++;
		}
	}
}
void undo(){
	if(st.empty()) return;
	if(st.top().xrk==-1){
		st.pop();return;
	}
	op t=st.top();st.pop();
	int xrt=t.xroot,yrt=t.yroot,xrk=t.xrk,yrk=t.yrk;
	fa[xrt]=xrt;fa[yrt]=yrt;
	rk[xrt]=xrk;rk[yrt]=yrk;
	return;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m;init();
	while(m--){
		int op,x,y;cin>>op;
		if(op==1){
			cin>>x>>y;
			merge(x,y);
		}
		else if(op==2) undo();
		else{
			cin>>x>>y;
			cout<<((find(x)==find(y))?"Yes":"No")<<"\n";
		}
	}
	return 0;
}
