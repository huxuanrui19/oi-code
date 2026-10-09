#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e3+10;
struct oper{
	int x,y,op;
}a[N];
int cnt=0,fa[N*2],b[N*2];
int fi(int s){
	if(s!=fa[s]) return fa[s]=fi(fa[s]);
	return s;
}
void mer(int x,int y){
	x=fi(x);
	y=fi(y);
	if(x!=y) fa[x]=y; 
}
int main(){
	int n,m;
	cin>>n>>m;
	string s;
	for(int i=1;i<=m;i++){
		cin>>a[i].x>>a[i].y>>s;
		a[i].x--;
		if(s[0]=='o') a[i].op=1;
		else a[i].op=0;
		b[++cnt]=a[i].x;
		b[++cnt]=a[i].y;
	}
	sort(b+1,b+cnt+1);
	int l=unique(b+1,b+cnt+1)-b-1;
	for(int i=1;i<=l*2;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		a[i].x=lower_bound(b+1,b+l+1,a[i].x)-b;
		a[i].y=lower_bound(b+1,b+l+1,a[i].y)-b;
		if(a[i].op==0){
			if(fi(a[i].x)==fi(a[i].y+l)||fi(a[i].x+l)==fi(a[i].y)){
				cout<<i-1;
				return 0;
			}
			else{
				mer(a[i].x,a[i].y);
				mer(a[i].x+l,a[i].y+l);
			}
		}
		else{
			if(fi(a[i].x)==fi(a[i].y)||fi(a[i].x+l)==fi(a[i].y+l)){
				cout<<i-1;
				return 0;
			}
			else{
				mer(a[i].x,a[i].y+l);
				mer(a[i].x+l,a[i].y);
			}
		}
	}
	cout<<m;
	return 0;
}
