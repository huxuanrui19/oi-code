#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10,M=20;
const ll inf=1e18,mod=1e9+7;
int n,q;
ll LOG2[N],x[N],sum[N],sum2[N],st[M][N];
void init(){
    LOG2[0]=-1;for(int i=1;i<=n;i++) LOG2[i]=LOG2[i>>1]+1;
    for(int i=1;i<=n;i++) st[0][i]=x[i];
    for(int j=1;j<M;j++){
        for(int i=1;i+(1<<j)-1<N;i++){
            st[j][i]=min(st[j-1][i],st[j-1][i+(1<<(j-1))]);
        }
    }
}
ll query(int l,int r){
    int p=LOG2[r-l+1];
    return min(st[p][l],st[p][r-(1<<p)+1]);
}
int main(){
    //freopen("split.in","r",stdin);
    //freopen("split.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>x[i];
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+x[i];
    for(int i=1;i<=n;i++) sum2[i]=sum2[i-1]+x[i]*x[i];
    init();
    for(int i=1;i<=q;i++){
        int l,r;ll S;cin>>l>>r>>S;
        if((sum[r]-sum[l-1])>S) cout<<"-1\n";
        else{
            ll res=S-(sum[r]-sum[l-1]);
            if(res==0){
                ll mi=query(l,r);
                ll s1=sum[r]-sum[l-1]-mi;
                ll s2=sum2[r]-sum2[l-1]-mi*mi;
                ll ans=s1*S-(s2+s1*s1)/2;
                cout<<ans<<"\n";
            }
            else{
                ll mi=min(query(l,r),res);
                ll s1=sum[r]-sum[l-1]+res-mi;
                ll s2=sum2[r]-sum2[l-1]+res*res-mi*mi;
                ll ans=s1*S-(s2+s1*s1)/2;
                cout<<ans<<"\n";
            }
        }
    }
    return 0;
}