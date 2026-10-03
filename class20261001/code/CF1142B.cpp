#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int nxt[maxn][20],match[maxn],lst[maxn],n,m,q;
int a[maxn],b[maxn],p[maxn];
int main(){
    ios::sync_with_stdio(0);
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++)cin>>p[i];
    for(int i=1;i<=m;i++)cin>>a[i];
    for(int i=1;i<=n;i++)match[p[i]]=p[i%n+1];
    for(int i=1;i<=n;i++)lst[i]=m+1;
    for(int i=m;i>=1;i--){
        nxt[i][0]=lst[match[a[i]]];
        lst[a[i]]=i;
    }
    for(int j=1;(1<<j)<=m;j++){
        for(int i=1;i+(1<<j)-1<=m;i++){
            nxt[i][j]=nxt[nxt[i][j-1]][j-1];
            if(!nxt[i][j])nxt[i][j]=m+1;
        }
    }
    for(int i=1;i<=m;i++){
        int t=n-1,now=i;
        for(int j=19;j>=0;j--){
            if((t&(1<<j)))now=nxt[now][j];
        }
        if(!now)now=m+1;
        b[i]=now;
    }
    for(int i=m-1;i>=1;i--)b[i]=min(b[i],b[i+1]);
    while(q--){
        int l,r;
        cin>>l>>r;
        if(b[l]<=r)cout<<1;
        else cout<<0;
    }
}