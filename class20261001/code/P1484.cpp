#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn=2e6+5;
int n,m,ans,a[maxn];
ll val[maxn];
int nxt[maxn],lst[maxn];
struct node{
    int x;
    ll val;
    node(){}
    node(ll _val,int _x){val=_val,x=_x;}
    bool operator<(const node &t)const{
        return val<t.val;
    }
};
priority_queue<node>q;
bool vis[maxn];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]),q.push(node(a[i],i));
    for(int i=1;i<=n;i++){
        lst[i]=i-1;
        nxt[i]=i+1;
        val[i]=a[i];
    }
    ll now=0,ans=0;
    while(m--){
        while(vis[q.top().x])q.pop();
        node t=q.top();
        q.pop();
        vis[nxt[t.x]]=vis[lst[t.x]]=1;
        now+=t.val;
        t.val=-t.val+val[nxt[t.x]]+val[lst[t.x]];
        val[t.x]=t.val;
        lst[nxt[nxt[t.x]]]=t.x;
        nxt[t.x]=nxt[nxt[t.x]];
        nxt[lst[lst[t.x]]]=t.x;
        lst[t.x]=lst[lst[t.x]];
        q.push(t);
        ans=max(now,ans);
    }
    printf("%lld",ans);
    return 0;
  }
