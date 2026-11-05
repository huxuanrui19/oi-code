#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=4e2+10;
const int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
const ll inf=1e9,mod=1e9+7;
int r,c,d[N][N];
char ch[N][N];
bool ex[N][N];
int main(){
    freopen("grid.in","r",stdin);
    freopen("grid.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>r>>c;
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            cin>>ch[i][j];
            ex[i][j]=1;
            d[i][j]=inf;
        }
    }
    if(r==1&&c==1){
        cout<<"2\n";
        return 0;
    }
    queue<pair<int,int> > q;
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            if(ch[i][j]=='N'){
                if((ex[i][j-1]==0&&ex[i+1][j]==0)||(ex[i-1][j]==0&&ex[i][j+1]==0)){
                    q.push({i,j});
                    d[i][j]=2;
                }
            }
            else{
                if((ex[i][j+1]==0&&ex[i+1][j]==0)||(ex[i-1][j]==0&&ex[i][j-1]==0)){
                    q.push({i,j});
                    d[i][j]=2;
                }
            }
        }
    }
    while(!q.empty()){
        auto p=q.front();int x=p.first,y=p.second;q.pop();
        if(ex[x][y]==0) continue;
        ex[x][y]=0;
        for(int i=0;i<4;i++){
            int nx=x+dir[i][0],ny=y+dir[i][1];
            if(nx>r||nx<=0||ny>c||ny<=0) continue;
            if(ex[nx][ny]==0) continue;
            if(ch[nx][ny]=='N'){
                if((ex[nx][ny-1]==0&&ex[nx+1][ny]==0)||(ex[nx-1][ny]==0&&ex[nx][ny+1]==0)){
                    q.push({nx,ny});
                    d[nx][ny]=d[x][y]+2;
                }
            }
            else{
                if((ex[nx][ny+1]==0&&ex[nx+1][ny]==0)||(ex[nx-1][ny]==0&&ex[nx][ny-1]==0)){
                    q.push({nx,ny});
                    d[nx][ny]=d[x][y]+2;
                }
            }
        }
    }
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            if(d[i][j]==inf) cout<<"-1 ";
            else cout<<d[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}