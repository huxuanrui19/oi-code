#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e3+10;
const ll mod=998244353;
int n,a[N],pos[N];
int cnt,vis[N];vector<int> v[2];
ll C[N][N];
void init(){
    for(int i=0;i<N;i++){
        C[i][0]=1;
        for(int j=1;j<=i;j++){
            C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
        }
    }
}

bool getcir(){
    cnt=0;
    v[0].clear();v[1].clear();
    for(int i=1;i<=n;i++) vis[i]=0;
    for(int i=1;i<=n;i++){
        if(vis[i]) continue;
        ++cnt;vis[i]=1;
        if(cnt>2) return 0;
        v[cnt-1].push_back(i);
        int j=pos[i];
        while(j!=i){
            vis[j]=1;
            v[cnt-1].push_back(j);
            j=pos[j];
        }
    }
    return (cnt==2);
}

int getdir(int x){
    ll num1=0,num2=0;
    if((int)v[x].size()<=2) return 0;
    for(int i=0;i<(int)v[x].size();i++){
        int u=v[x][i],v=pos[u];
        num1+=(v-u+n)%n;
        num2+=(u-v+n)%n;
    }
    if(num1==n) return 1;
    else if(num2==n) return -1;
    else return 2;
}
int flag[2];
int up[N<<1],lab[N];
void build(int sh){
    for(int x=0;x<=1;x++){
        for(auto i:v[x]){
            lab[i]=(x==sh)?1:0; //clockwise 1,counterclockwise 0
        }
    }
    for(int i=1;i<=2*n;i++){
        int e=i%n+1;
        up[i]=(lab[e]==0 ? 1 : 0);  //x>x+1 1 x<x+1 0
    }
}
ll dp[N<<1][N<<1];
ll f(int sh,int ni){
    if(flag[sh]!=0&&flag[sh]!=1) return 0;
    if(flag[ni]!=0&&flag[ni]!=-1) return 0;
    build(sh);
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n*2;i++) dp[i][i]=1;
    for(int l=2;l<=n-1;l++){
        for(int i=1;i+l-1<=2*n;i++){
            int j=i+l-1;
            for(int x=i;x<=j;x++){
                if(x>i&&up[x-1]!=1) continue;
                if(x<j&&up[x]!=0) continue;
                ll le=1,re=1;
                if(x>i) le=dp[i][x-1];
                if(x<j) re=dp[x+1][j];
                dp[i][j]=(dp[i][j]+le*re%mod*C[l-1][x-i]%mod)%mod;
            }
        }
    }
    ll ans=0;
    for(int i=1;i<=n;i++){
        int pre=(i==1)?n:i-1;
        if(up[pre]!=1||up[i]!=0) continue;
        ans=(ans+dp[i+1][i+n-1])%mod;
    }
    return ans;
}

int main(){
    //freopen("hack.in","r",stdin);
    //freopen("perm.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    init();
    int c,t;cin>>c>>t;
    while(t--){
        cin>>n;for(int i=1;i<=n;i++) cin>>a[i];
        if(n==1){
            cout<<"1\n";
            continue;
        }
        for(int i=1;i<=n;i++) pos[a[i]]=i;
        if(!getcir()){
            cout<<"0\n";
            continue;
        }
        flag[0]=getdir(0);flag[1]=getdir(1);
        if((flag[0]-2)*(flag[1]-2)==0){
            cout<<"0\n";
            continue;
        }
        ll ans=0;
        ans=(ans+f(0,1))%mod;
        ans=(ans+f(1,0))%mod;
        cout<<ans<<"\n";
    }
    return 0;
}
