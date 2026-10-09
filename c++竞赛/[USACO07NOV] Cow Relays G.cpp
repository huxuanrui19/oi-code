#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100+10;
struct edge{
	int u,v;
	ll w;
}e1[N];
int cnt=0,lis[N<<1];
struct maxi{
	ll a[N][N];
}ed;
maxi operator *(const maxi &x,const maxi &y){
	maxi c;
	memset(c.a,0x3f,sizeof(c.a));
	for(int i=1;i<=cnt;i++){
		for(int j=1;j<=cnt;j++){
			for(int k=1;k<=cnt;k++){
				c.a[i][j]=min(x.a[i][k]+y.a[k][j],c.a[i][j]);
			} 
		}
	}
	return c;
}
maxi mxfp(maxi k,ll b){
	maxi ans=k;
	b--;
	while(b){
		if(b&1) ans=ans*k;
		b>>=1;
		k=k*k;
	}
	return ans;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	int n,t,s,e;
	cin>>n>>t>>s>>e;
	for(int i=1;i<=t;i++){
		cin>>e1[i].w>>e1[i].u>>e1[i].v;
		lis[++cnt]=e1[i].u;
		lis[++cnt]=e1[i].v;
	}
	sort(lis+1,lis+cnt+1);
	cnt=unique(lis+1,lis+cnt+1)-lis-1;
	int ns=lower_bound(lis+1,lis+cnt+1,s)-lis;
	int ne=lower_bound(lis+1,lis+cnt+1,e)-lis;
	memset(ed.a,0x3f,sizeof(ed.a));
	for(int i=1;i<=t;i++){
		int nu=lower_bound(lis+1,lis+1+cnt,e1[i].u)-lis;
		int nv=lower_bound(lis+1,lis+1+cnt,e1[i].v)-lis;
		ed.a[nu][nv]=ed.a[nv][nu]=e1[i].w;
	}
	ed=mxfp(ed,n);
	cout<<ed.a[ns][ne];
	return 0;
}

