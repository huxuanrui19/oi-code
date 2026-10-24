#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
int fa[N];
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
	}
	for(int i=1;i<=m;i++){
		int z,x,y;
		cin>>z>>x>>y;
		if(z==1){
			mer(x,y);
		}
		else{
			if(fi(x)==fi(y)){
				cout<<"Y"<<endl;
			}
			else{
				cout<<"N"<<endl;
			}
		}
	}
	return 0;
}

