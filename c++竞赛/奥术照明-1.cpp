#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e3+10;
const int dx[]={1,0,-1,0};
const int dy[]={0,1,0,-1};
int n,m,mp[N][N],vis[2][N][N],d[2][N][N];
struct node{
	int x,y;
	bool check(){
		return x<=n&&y<=m&&x>=1&&y>=1;
	}
};
queue<node> q;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			char ch;
			cin>>ch;
			mp[i][j]=(ch-'0');
			if(ch=='1') q.push((node){i,j});
		}
	}
	for(int i=0;q.size();i++){
		int size=q.size();
		while(size--){
			node u=q.front();
			q.pop();
			d[i%2][u.x][u.y]=i;
			for(int j=0;j<4;j++){
				node v=(node){u.x+dx[j],u.y+dy[j]};
				if((!v.check())||vis[(i+1)%2][v.x][v.y]==1) continue;
				vis[(i+1)%2][v.x][v.y]=1;
				q.push(v);
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int g=min(min(i,j),min(n-i+1,m-j+1));
			int odd=min(d[1][i][j],(g%2==1?g:g+1));
			int eve=min(d[0][i][j],(g%2==0?g:g+1));
			ans=max(ans,max(odd-2,eve-2));
		} 
	}
	cout<<ans;
	return 0;
}

