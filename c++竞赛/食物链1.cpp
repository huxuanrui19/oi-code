#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e4+10;
int ans,fa[N*3];
int fi(int s){
	if(s!=fa[s]){
		return fa[s]=fi(fa[s]);
	} 
	return fa[s];
}
void mer(int x,int y){
	int rx=fi(x);
	int ry=fi(y);
	fa[ry]=rx;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=3*n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=k;i++){
		int re,x,y;
		cin>>re>>x>>y;
		if(x>n||y>n) ans++;
		else if(re==1){
			if(fi(x)==fi(y+n)||fi(x)==fi(y+n+n)) ans++;
			else{
				mer(x,y);
				mer(x+n,y+n);
				mer(x+n+n,y+n+n);
			}
		}
		else{
			if(fi(x)==fi(y)||fi(x)==fi(y+n)) ans++;
			else{
				mer(x+n,y);
				mer(x+n+n,y+n);
				mer(x,y+n+n);
			}
		}
	}
	cout<<ans;
	return 0;
}

