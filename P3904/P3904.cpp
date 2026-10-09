#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100+10,M=55;
const ll maxn=1e18,mod=1e9+7;
struct bInt{
    int len=0,a[N];
    void init(){len=0;memset(a,0,sizeof(a));}
    bInt operator +(const bInt &x){
        bInt c;c.init();
        for(int i=1,cnt=0;i<=len||i<=x.len||cnt;i++){
            c.len++;
            c.a[i]=(a[i]+x.a[i]+cnt)%10;
            cnt=(a[i]+x.a[i]+cnt)/10;
        }
        return c;
    }
    bInt operator *(const int &x){
        bInt c;c.init();
        for(int i=1,cnt=0;i<=len||cnt;i++){
            c.len++;
            c.a[i]=(a[i]*x+cnt)%10;
            cnt=(a[i]*x+cnt)/10;
        }
        return c;
    }
}stl2[M][M];
int n,m;
void calc(){
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++) stl2[i][j].init();
    }
    stl2[0][0].a[1]=1;stl2[0][0].len++;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            stl2[i][j]=stl2[i-1][j-1]+stl2[i-1][j]*j;
        }
    }
}
int main(){
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n>>m;
    if(n<m) cout<<0;
    else{
        calc();int flag=0;
        for(int i=stl2[n][m].len;i>=1;i--){
            cout<<stl2[n][m].a[i];
        }
    }
    return 0;
}