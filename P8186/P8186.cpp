#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e2+10;
int n,a[N][N],b[N][N],g[N][N];
int main(){
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
            b[i][a[i][j]]=j;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j) continue;
            if(b[i][i]>=b[i][j]) g[i][j]=1;
        }
    }
    for(int k=1;k<=n;k++){
        for(int j=1;j<=n;j++){
            for(int i=1;i<=n;i++) g[i][j]|=(g[i][k]&&g[k][j]);
        }
    }
    for(int i=1;i<=n;i++){
        ll maxn=b[i][i],idx=i;
        for(int j=1;j<=n;j++){
            if(i==j) continue;
            else if(g[i][j]&&g[j][i]){
                if(maxn>b[i][j]) maxn=b[i][j],idx=j;
            }
        }
        cout<<idx<<"\n";
    }
    return 0;
}