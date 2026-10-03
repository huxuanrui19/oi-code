#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+5;
int stk[maxn],tp,lst[maxn][2],nxt[maxn][2];
int n,a[maxn],ans[maxn];
int dp[maxn];
int main(){
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        while(tp&&a[stk[tp]]>a[i])tp--;
        lst[i][0]=stk[tp];
        stk[++tp]=i;
    }
    tp=0;
    stk[0]=n+1;
    for(int i=n;i>=1;i--){
        while(tp&&a[stk[tp]]>a[i])tp--;
        nxt[i][0]=stk[tp];
        stk[++tp]=i; 
    }  
    tp=0;
    stk[0]=0;
    for(int i=1;i<=n;i++){
        while(tp&&a[stk[tp]]<a[i])tp--;
        lst[i][1]=stk[tp];
        stk[++tp]=i;
    }
    tp=0;
    stk[0]=n+1;
    for(int i=n;i>=1;i--){
        while(tp&&a[stk[tp]]<a[i])tp--;
        nxt[i][1]=stk[tp];
        stk[++tp]=i; 
    }  
    for(int i=1;i<=n;i++)dp[i]=n;
    dp[1]=0;
    for(int i=1;i<=n;i++){
        dp[i]=min(dp[i],dp[i-1]+1);//条件1
        if(lst[i][0])dp[i]=min(dp[i],dp[lst[i][0]]+1);//条件2情况1
        if(lst[i][1])dp[i]=min(dp[i],dp[lst[i][1]]+1);//条件3情况1
        if(nxt[i][0]<=n)dp[nxt[i][0]]=min(dp[nxt[i][0]],dp[i]+1);//条件2情况2
        if(nxt[i][0]<=n)dp[nxt[i][1]]=min(dp[nxt[i][1]],dp[i]+1);//条件3情况2
    }
    cout<<dp[n]<<endl;
    return 0;
}