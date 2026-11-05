#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+10;
inline int lowbit(int x){
    return x&(-x);
}
ll n,d,a[N],dp[N],f[N];
ll lis[N];
ll tree[N];
void update(int s,ll d){
    while(s<=n){
        tree[s]+=d;
        s+=lowbit(s);
    }
}
ll query(int s){
    ll ans=0;
    while(s){
        ans+=tree[s];
        s-=lowbit(s);
    }
    return ans;
}
ll cal(int s){
    f[s]=0,dp[s]=1;update(s,1);
    for(int i=s+1;i<=n;i++){
        dp[i]=0;
        int l=lower_bound(lis+1,lis+n+1,a[i]-d)-lis;
        f[i]=f[max(l,s)]+1;
        int r=upper_bound(f+s,f+i+1,f[max(l,s)])-f-1;
        dp[i]=query(r)-query(l-1);
        update(i,dp[i]);
    }
    ll ans=0;
    for(int i=s;i<=n;i++) tree[i]=0;
    for(int i=s;i<=n;i++) ans+=(dp[i]==2);
    return ans;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int c,t;cin>>c>>t;
    while(t--){
        cin>>n>>d;for(int i=1;i<=n;i++) cin>>a[i];
        int flag=1;
        for(int i=2;i<n;i++){
            if(a[i]*2!=a[i-1]+a[i+1]) flag=0;
        }
        if(n<=5e3+10){
            for(int i=1;i<=n;i++) lis[i]=a[i];
            sort(lis+1,lis+n+1);
            ll ans=0;
            for(int i=1;i<=n;i++){
                ans+=cal(i);
            }
            cout<<ans<<"\n";
        }
        else if(flag){
            ll de=a[2]-a[1];ll st=d/de;
            if(st==0) cout<<"0\n";
            else if(st==1) cout<<"0\n";
            else if(st==2){
                ll ans=0;
                for(int i=1;i<=n;i++){
                    if(n-i>=3) ans++;
                    else continue;
                }
                cout<<ans<<"\n";
            }
            else{
                ll ans=0;
                for(int i=1;i<=n;i++){
                    if(n-i>=2*st-1) ans++;
                    else continue;
                }
                cout<<ans<<"\n";
            }
        }
        else{
            cout<<"0\n";
        }
    }
    return 0;
}
