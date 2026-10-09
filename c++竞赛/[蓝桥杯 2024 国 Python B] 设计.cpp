#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3e5+10;
struct op{
	int xroot,yroot,xrank,yrank;
};
int fa[N],rk[N];
stack<op> his;
void init(){
	memset(rk,0,sizeof(rk));
	for(int i=1;i<N;i++){
		fa[i]=i;
	}
}
int find(int x){
	while(x!=fa[x]){
		x=fa[x];
	}
	return x;
}
void merge(int x,int y){
	int xrt=find(x),yrt=find(y);
	if(xrt==yrt) his.push(op{-1,-1,-1,-1});
	else if(rk[xrt]<rk[yrt]){
		his.push(op{xrt,yrt,rk[xrt],rk[yrt]});
		fa[xrt]=yrt;
	}
	else{
		his.push(op{yrt,xrt,rk[yrt],rk[xrt]});
		fa[yrt]=xrt;
		if(rk[xrt]==rk[yrt]){
			rk[xrt]++;
		}
	}
}
void undo(){
	if(his.empty()) return;
	op cur=his.top();
	his.pop();
	int ch=cur.xroot,pr=cur.yroot,ch_rk=cur.xrank,pr_rk=cur.yrank;
	if(ch==-1) return;
	fa[ch] = ch;
    rk[ch] = ch_rk;
    rk[pr] = pr_rk;
}
void judge(int x,int y){
	if(find(x)==find(y)) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,m;
	cin>>n>>m;
	init();
	while(m--){
		int type,xi,yi;
		cin>>type;
		if(type==2){
			undo();
		}
		else{
			cin>>xi>>yi;
			if(type==1){
				merge(xi,yi);
			}
			else{
				judge(xi,yi);
			}
		}
	}
	return 0;
}

