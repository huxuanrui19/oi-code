#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e3+10;
const ll inf=1e18,mod=1e9+7;
int n,m,k;
int a[N][N],b[N][N],c[N][2];
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
    int cnt=0;
    for(int i=1;i<=k;i++) c[i][0]=c[i][1]=-1;
    while(k--){
        int opt,i,x;cin>>opt>>i;
        if(opt==1){
            cin>>x;
            for(int j=1;j<=n;j++){
                ++cnt;a[cnt][j]=a[cnt-1][j]+x*(j==i);
            }
        }
        else if(opt==2){
            string s;cin>>s;
            if(s=="win"&&c[i][1]==-1) c[i][1]=cnt;
            else c[i][0]=cnt;
        }
    }
    cout<<"Yes\n";
    return 0;
}