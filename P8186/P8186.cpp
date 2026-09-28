#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e2+10;
int n,ans[N],a[N][N],b[N][N];
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
    for(int i=1;i<=n;i++) ans[i]=i;
    for(int t=1;t<=n;t++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(b[i][ans[i]]>=b[i][ans[j]]&&b[j][ans[j]]>=b[j][ans[i]]){
                    swap(ans[i],ans[j]);
                }
            }
        }
    }
    for(int i=1;i<=n;i++) cout<<ans[i]<<"\n";
    return 0;
}