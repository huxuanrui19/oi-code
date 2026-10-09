#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=80+10;
int n,m,a[N][N],d[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
vector<int> g[N*N];
vector<int> gt[N*N];
int cnt=0,ans,vis[N*N],col[N*N],flag[N*N],match[N*N],type[N][N];
vector<int> lft;
bool judge(int x,int y){
	if(x<=n&&x>=1&&y<=m&&y>=1) return 1;
	return 0;
}
int f(int x,int y){return (x-1)*m+y;}
void dfs(int u,int c){
	col[u]=c;
	for(auto d:g[u]){
		if(!col[d]) dfs(d,3-c);
	}
	return;
}
bool find(int u){
	for(auto d:gt[u]){
		if(flag[d]) continue;
		flag[d]=1;
		if(!match[d]||find(match[d])){
			match[d]=u;
			return 1;
		}
	}
	return 0;
}
void hung(){
	memset(match,0,sizeof(match));
	for(auto i:lft){
		memset(flag,0,sizeof(flag));
		if(find(i)) ans++;
	}
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			char c;cin>>c;
			a[i][j]=c-'0';
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
            for(int k=0;k<4;k++){
				int nx=i+d[k][0],ny=j+d[k][1];
				if(!judge(nx,ny)) continue;
                if(a[nx][ny]==2) type[i][j]=1;
            }
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]!=0||type[i][j]) continue;
			for(int k=0;k<4;k++){
				int nx=i+d[k][0],ny=j+d[k][1];
				if(!judge(nx,ny)) continue;
				if(a[nx][ny]==1||type[nx][ny]==1) continue;
				g[f(i,j)].push_back(f(nx,ny));
				g[f(nx,ny)].push_back(f(i,j));
			}
		}
	}
	/*for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			for(auto d:g[f(i,j)]){
				cout<<d<<" ";
			}
			cout<<"\n";
		}
	}*/
	int sum=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int mark=0;
            for(int k=0;k<4;k++){
				int nx=i+d[k][0],ny=j+d[k][1];
				if(!judge(nx,ny)) continue;
                if(a[nx][ny]==2) mark=1;
            }
			if(a[i][j]==0&&vis[f(i,j)]==0&&mark==0){
				ans=0;
				memset(col,0,sizeof(col));
				lft.clear();
				dfs(f(i,j),1);
				int siz=0;
				for(int i=1;i<=n;i++){
					for(int j=1;j<=m;j++){
						if(col[f(i,j)]==0) continue;
						vis[f(i,j)]=1;siz++;
						if(col[f(i,j)]==1){
							lft.push_back(f(i,j));
							for(auto d:g[f(i,j)]){
								if(col[d]==2) gt[f(i,j)].push_back(d);
							}
						}
					}
				}
				hung();
				//cout<<siz<<" "<<ans<<"\n";
                sum+=siz-ans;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==2) sum++;
		}
	}
	cout<<sum;
	return 0;
}
