#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+5;
int stk[maxn],tp,lst[maxn],nxt[maxn];
int n,a[maxn],ans[maxn];
int main(){
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        while(tp&&a[stk[tp]]>=a[i])tp--;
        lst[i]=stk[tp];
        stk[++tp]=i;
    }
    tp=0;
    stk[0]=n+1;
    for(int i=n;i>=1;i--){
        while(tp&&a[stk[tp]]>=a[i])tp--;
        nxt[i]=stk[tp];
        stk[++tp]=i; 
    }  
    for(int i=1;i<=n;i++){
        int len=nxt[i]-lst[i]-1;
        ans[len]=max(ans[len],a[i]);
    }
    for(int i=n;i>=1;i--)ans[i]=max(ans[i],ans[i+1]);
    for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
    return 0;
}