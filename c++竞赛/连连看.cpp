#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
const int N=5e3+10,M=1e3+10;
int n,m,k;
struct pt{
	int xpos1,ypos1,xpos2,ypos2;
}x[N];
struct pt1{
	int xpos,ypos;
};
int a[M][M],mp[M][M];
bool cal(pt1 x1,pt1 y1){
	int xa=x1.xpos,xb=y1.xpos,ya=x1.ypos,yb=y1.ypos;
	if(xb==xa&&yb==ya) return 1;
	else if(xb==xa){
		if(ya<yb) swap(ya,yb);
		int num=a[xa][ya-1]-a[xa][yb]-a[xa-1][ya-1]+a[xa-1][yb];
		return (num==0);
	}
	else{
		if(xa<xb) swap(xa,xb);
		int num=a[xa-1][ya]-a[xb][ya]-a[xa-1][ya-1]+a[xb][ya-1];
		return (num==0);
	}
}
int main(){
	//freopen("linking.in","r",stdin);
	//freopen("linking.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=k;i++){
		cin>>x[i].xpos1>>x[i].ypos1>>x[i].xpos2>>x[i].ypos2;
		a[x[i].xpos1][x[i].ypos1]++;
		a[x[i].xpos2][x[i].ypos2]++;
		mp[x[i].xpos1][x[i].ypos1]=i;
		mp[x[i].xpos2][x[i].ypos2]=i;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			a[i][j]+=a[i][j-1]+a[i-1][j]-a[i-1][j-1];
		}
	}
	int cnt=0;
	for(int i=1;i<=k;i++){
		int ans=0;
		pt1 p1=(pt1){x[i].xpos1,x[i].ypos1},p2=(pt1){x[i].xpos2,x[i].ypos2};
		for(int j=1;j<=n;j++){
			pt1 p3=(pt1){j,x[i].ypos1},p4=(pt1){j,x[i].ypos2};
			if((mp[j][x[i].ypos1]!=0&&mp[j][x[i].ypos1]!=i)||(mp[j][x[i].ypos2]!=0&&mp[j][x[i].ypos2]!=i)) continue;
			if(cal(p1,p3)&&cal(p3,p4)&&cal(p4,p2)) ans=1;
		}
		for(int j=1;j<=m;j++){
			pt1 p3=(pt1){x[i].xpos1,j},p4=(pt1){x[i].xpos2,j};
			if((mp[x[i].xpos1][j]!=0&&mp[x[i].xpos1][j]!=i)||(mp[x[i].xpos2][j]!=0&&mp[x[i].xpos2][j]!=i)) continue;
			if(cal(p1,p3)&&cal(p3,p4)&&cal(p4,p2)) ans=1;
		}
		if(ans==1) cnt++;
	}
	cout<<cnt;
	return 0;
}

