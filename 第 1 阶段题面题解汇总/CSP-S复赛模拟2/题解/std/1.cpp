#include<bits/stdc++.h>
#define maxn 200005
#define ll long long
using namespace std;
int stk[maxn],tot=0;
int n;
int a[maxn],deg[maxn],ans[maxn];
basic_string<int> edge[maxn];
void addedge(int x,int y) {deg[y]++; edge[x]+=y;}
priority_queue<int> Q;
void topo()
{
    for (int i=1;i<=n;i++) if (deg[i]==0) Q.push(-i);
    for (int i=1;i<=n;i++)
    {
        int now=-Q.top(); Q.pop();
        ans[now]=i;
        for (int j:edge[now]) {deg[j]--; if (deg[j]==0) Q.push(-j);}
    }
    for (int i=1;i<=n;i++) cout<<ans[i]<<" "; cout<<endl;
}
int main()
{
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    stk[++tot]=1;
    for (int i=2;i<=n;i++)
    {
        while (tot>=a[i]) {addedge(i,stk[tot]); tot--;}
        if (tot>=1) addedge(stk[tot],i);
        stk[++tot]=i;
    }
    topo();
}