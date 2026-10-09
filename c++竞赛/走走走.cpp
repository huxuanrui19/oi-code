#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
struct node{
	int nx,ny,dir,l,dis;
};
int sx,sy,ex,ey;
const int x[]={0,1,-1,0,0};
const int y[]={0,0,0,-1,1};
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,m;
	cin>>n>>m;
	int map[n+10][m+10];
	bool vis[n+10][m+10][5][5];
	for(int i=0;i<n+10;i++){
		for(int j=0;j<m+10;j++){
			map[i][j]=0;
			for(int k=0;k<5;k++){
				for(int l=0;l<5;l++){
					vis[i][j][k][l]=0;
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			char c;
			cin>>c;
			if(c=='S'){
				sx=i;
				sy=j;
			}
			else if(c=='E'){
				ex=i;
				ey=j;
			}
			if(c=='#'){
				map[i][j]=1;
			}
		}
	}
	queue<node> q;
	q.push({sx,sy,0,0,0});
	int ans=-1;
	while(!q.empty()){
		node tmp=q.front();
		q.pop();
		int nx=tmp.nx,ny=tmp.ny,len=tmp.l,dir=tmp.dir,dis=tmp.dis;
		if(nx==ex&&ny==ey){
			ans=dis;
			break;
		}
		for(int i=1;i<=4;i++){
			int tx=nx+x[i],ty=ny+y[i];
			if(tx>n||tx<=0||ty>m||ty<0||map[tx][ty]) continue;
			if(dir==i&&(len+1)>=4) continue;
			int tl=(dir==i)?(len+1):1;
			if(vis[tx][ty][i][tl]) continue;
			q.push({tx,ty,i,tl,dis+1});
			vis[tx][ty][i][tl]=1;
		}
	}
	cout<<ans;
	return 0;
}

