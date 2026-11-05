#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3e5+10;
const ll inf=1e18,mod=1e9+7;
int n,a[N],pre[N],nxt[N],tree[N];
ll tree1[N],dp[N];
inline int lowbit(int x){
    return x&(-x);
}
void update(int pos,int num,int type){
    for(int i=pos;i<N;i+=lowbit(i)){
        if(type==1) tree[i]=max(tree[i],num);
        else tree[i]=min(tree[i],num);
    }
}
int query(int pos,int type){
    int ans=(type==1?0:(n+1));
    for(int i=pos;i>0;i-=lowbit(i)){
        if(type==1) ans=max(ans,tree[i]);
        else ans=min(ans,tree[i]);
    }
    return ans;
}
void update1(int pos,ll num){
    if(pos<=0) return;
    for(int i=pos;i<N;i+=lowbit(i)){
        tree1[i]+=num;
        tree1[i]%=mod;
    }
}
ll query1(int pos){
    if(pos<0) return 0;
    ll ans=0;
    for(int i=pos;i>0;i-=lowbit(i)){
        ans+=tree1[i];ans%=mod;
    }
    return ans;
}
int main(){
    freopen("arrange.in","r",stdin);
    freopen("arrange.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    memset(tree,0,sizeof(tree));
    for(int i=1;i<=n;i++){
        pre[i]=query(a[i],1);
        update(a[i],i,1);
    }
    for(int i=1;i<N;i++) tree[i]=n+1;
    for(int i=n;i>=1;i--){
        nxt[i]=query(a[i],0);
        update(a[i],i,0);
    }
    //for(int i=1;i<=n;i++) cout<<pre[i]<<" "<<nxt[i]<<"\n";
    update1(1,1);
    for(int i=1;i<=n;i++){
        dp[i]+=query1(n)-query1(pre[i]);
        dp[i]=(dp[i]+mod)%mod;
        update1(nxt[i]-1,dp[i]);
    }
    ll ans=0;
    for(int i=n,minn=1e9;i>=1;i--){
        minn=min(minn,a[i]);
        if(minn==a[i]) ans+=dp[i],ans%=mod;
    }
    //for(int i=1;i<=n;i++) cout<<dp[i]<<" ";
    cout<<ans;
    return 0;
}