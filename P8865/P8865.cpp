#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e3+10;
const ll maxn=1e18,mod=998244353;
ll c,f;
int n,m,a[N][N],pos[N][N];
ll sum[N][N],sum2[N][N];
int main(){
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t,id;cin>>t>>id;
    while(t--){
        cin>>n>>m>>c>>f;
        for(int i=1;i<=n;i++){
            string s;
            cin>>s;
            for(int j=1;j<=m;j++){
                a[i][j]=(s[j-1]-'0')^1;
            }
        }
        memset(sum,0,sizeof(sum));
        memset(sum2,0,sizeof(sum2));
        for(int i=1;i<=n;i++){
            for(int j=m;j>=1;j--){
                if(a[i][j]==1) sum[i][j]=sum[i][j+1]+1;
                else sum[i][j]=0;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                sum[i][j]=max(sum[i][j]-1,0ll);
            }
        }
        for(int j=1;j<=m;j++){
            pos[n+1][j]=n+1;
            for(int i=n;i>=1;i--){
                if(a[i][j]==1) pos[i][j]=pos[i+1][j];
                else pos[i][j]=i;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(a[i][j]==1) sum2[i][j]=sum[i][j]*(pos[i][j]-i-1)%mod;
                else sum2[i][j]=0;
            }
        }
        for(int i=n;i>=1;i--){
            for(int j=1;j<=m;j++){
                sum2[i][j]+=sum2[i+1][j];
                sum2[i][j]%=mod;
            }
        }
        for(int i=n;i>=1;i--){
            for(int j=1;j<=m;j++){
                sum[i][j]+=sum[i+1][j];
                sum[i][j]%=mod;
            }
        }
        ll cc=0,ff=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(pos[i][j]-i>=3){
                    cc+=(sum[i+2][j]-sum[pos[i][j]][j])*(sum[i][j]-sum[i+1][j])%mod;
                    cc%=mod;
                }
                if(pos[i][j]-i>=4){
                    ff+=(sum2[i+2][j]-sum2[pos[i][j]-1][j])*(sum[i][j]-sum[i+1][j])%mod;
                    ff%=mod;
                }
            }
        }
        cout<<(cc*c%mod)<<" "<<(ff*f%mod)<<"\n";
    }
    return 0;
}