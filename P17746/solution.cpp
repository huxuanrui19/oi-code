#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e3+10;
const ll inf=1e18,mod=1e9+7;
int n,m,k,cnt,a[N][N],b[N][N],sta[N][N];
bool vis1[N][N],vis2[N][N];
int main(){
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++) cin>>a[0][i];
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++) cin>>b[i][j];
    }
    memset(sta,-1,sizeof(sta));
    for(int i=1;i<=k;i++){
        int opt;cin>>opt;
        if(opt==1){
            int j,d;cin>>j>>d;
            for(int x=1;x<=n;x++){
                if(x==j) a[cnt+1][x]=a[cnt][x]+d;
                else a[cnt+1][x]=a[cnt][x];
            }
            cnt++;
        }
        else if(opt==2){
            int j;string s;cin>>j>>s;
            sta[j][cnt]=(s=="win");
        }
    }
    int ans=1;
    memset(vis1,1,sizeof(vis1));
    memset(vis2,0,sizeof(vis2));
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(b[i][j]>a[cnt][j]){
                vis1[cnt][i]=0;
                break;
            }
        }
    }
    for(int i=cnt-1;i>=0;i--){
        int pos=0;
        for(int j=1;j<=n;j++){
            if(a[i][j]!=a[i+1][j]) pos=j;
        }
        for(int j=1;j<=m;j++){
            if(b[j][pos]>a[i][pos]) vis1[i][j]=0;
            else vis1[i][j]=vis1[i+1][j];
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(b[i][j]>a[cnt][j]) vis2[cnt][i]=1;
        }
    }
    for(int i=cnt-1;i>=0;i--){
        int pos=0;
        for(int j=1;j<=n;j++){
            if(a[i][j]!=a[i+1][j]) pos=j;
        }
        for(int j=1;j<=m;j++){
            if(b[j][pos]>a[i][pos]) vis2[i][j]=1;
            else vis2[i][j]=vis2[i+1][j];
        }
    }
    for(int i=1;i<=k;i++){
        int l=-1,r=-1;
        for(int j=0;j<=cnt;j++){
            if(sta[i][j]==0) l=j;
        }
        for(int j=0;j<=cnt;j++){
            if(sta[i][j]==1) r=j;
        }
        if(l==-1&&r==-1) continue;
        if(r==-1){
            int flag=0;
            for(int j=1;j<=m;j++){
                if(vis2[l][j]==1) flag=1;
            }
            ans=(ans&&flag);
        }
        else if(l==-1){
            int flag=0;
            for(int j=1;j<=m;j++){
                if(vis1[r][j]==1) flag=1;
            }
            ans=(ans&&flag);
        }
        else if(l<r){
            int flag=0;
            for(int j=1;j<=m;j++){
                if(vis2[l][j]&&vis1[r][j]) flag=1;
            }
            ans=(ans&&flag);
        }
        else ans=0;
    }
    if(ans) cout<<"Yes\n";
    else cout<<"No\n";
    return 0;
}