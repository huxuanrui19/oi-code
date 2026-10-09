#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3e4+10;
int fa[N],d[N],siz[N];
void init(){
	for(int i=1;i<N;i++){
		fa[i]=i;siz[i]=1;
	}
}
int fi(int x){
	if(fa[x]==x) return x;
	int t=fi(fa[x]);
	d[x]+=d[fa[x]];
	return fa[x]=t;                             //查找+路径压缩 
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	init();
	while(t--){
		char c;
		int x,y;
		cin>>c>>x>>y;
		if(c=='M'){
			int fx=fi(x),fy=fi(y);
			fa[fx]=fy;
			d[fx]=siz[fy];
			siz[fy]+=siz[fx];                        //合并 
		}
		else{
			if(fi(x)!=fi(y)) cout<<"-1"<<endl;       //判断 
			else cout<<(abs(d[x]-d[y])-1)<<endl;     //输出 
		}
	}
	return 0;
}

