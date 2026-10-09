#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e4+10;
int ans,fa[N],d[N];
int fi(int s){
	if(s!=fa[s]){
		int t=fa[s];
		fa[s]=fi(fa[s]);
		d[s]=(d[s]+d[t])%3;
	} 
	return fa[s];
}
void mer(int x,int y,int re){
	int rx=fi(x);
	int ry=fi(y);
	if(rx==ry){
		if((re-1)!=((d[x]-d[y]+3)%3)){
			ans++;
		}
	}
	else{
		fa[rx]=ry;
		d[rx]=(d[y]-d[x]+re-1)%3; 
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		fa[i]=i,d[i]=0;
	}
	for(int i=1;i<=k;i++){
		int re,x,y;
		cin>>re>>x>>y;
		if(x>n||y>n||(re==2&&x==y)) ans++;
		else mer(x,y,re);
	}
	cout<<ans;
	return 0;
}

