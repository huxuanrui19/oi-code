#include<bits/stdc++.h>
using namespace std;
const int maxn=3005;
typedef long long ll;
int q[maxn],hd,tl;
int n,m,a,b;
int w[maxn][maxn],c[maxn][maxn],d[maxn][maxn];
int g0,x,y,z;
const int inf=1e9;
int main(){
    ios::sync_with_stdio(0);
    cin>>n>>m>>a>>b;
    cin>>g0>>x>>y>>z;
    int lst=g0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            w[i][j]=lst;
            lst=(1ll*lst*x+y)%z;
        }
    }
    for(int i=1;i<=n;i++){//对每一行做单调队列
        hd=1;tl=0;
        w[i][0]=inf;
        for(int j=1;j<=m;j++){
            while(hd<=tl&&q[hd]+b<=j)hd++;
            while(hd<=tl&&w[i][q[tl]]>=w[i][j])tl--;
            q[++tl]=j;
            c[i][j]=w[i][q[hd]];
        }
    }
    for(int j=1;j<=m;j++){//对每一列做单调队列
        hd=1;tl=0;
        for(int i=1;i<=n;i++){
            while(hd<=tl&&q[hd]+a<=i)hd++;
            while(hd<=tl&&c[q[tl]][j]>=c[i][j])tl--;
            q[++tl]=i;
            d[i][j]=c[q[hd]][j];
        }
    }
    ll ans=0;
    for(int i=a;i<=n;i++){
        for(int j=b;j<=m;j++){
            ans+=d[i][j];
        }
    }
    printf("%lld\n",ans);
    return 0;
}