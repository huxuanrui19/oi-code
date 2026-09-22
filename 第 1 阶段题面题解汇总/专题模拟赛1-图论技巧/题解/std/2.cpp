#include<bits/stdc++.h>
#define ll long long 
#define maxn 200005
#define mod 998244353
using namespace std;
ll n,k,tot,cas;
ll x[maxn],y[maxn],v[maxn];
map<ll,ll> id;
int ID(ll x,ll y) {x=x*mod+y; if (id[x]==0) id[x]=++tot; return id[x];}
basic_string<int> edge[maxn];
ll siz[maxn],val[maxn];
struct nod{
    int x,y,v;
};
int cmp(nod x,nod y) {return x.v<y.v;}
vector<nod> A;
int fa[maxn];
int find(int x) {return x==fa[x]?x:fa[x]=find(fa[x]);}
int IN(int x,int y) {return x>=1 && x<=1000000000 && y>=1 && y<=1000000000;}
int dx[4]={0,0,-1,1},dy[4]={-1,1,0,0};
void init()
{
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n>>k>>cas;
    for (int i=1;i<=n;i++) 
    {
        cin>>x[i]>>y[i]>>v[i];
        ID(x[i],y[i]); siz[i]=1; val[i]=v[i];
    }
    
    for (int i=1;i<=n;i++)
    {
        int id1=ID(x[i],y[i]),id2;
        int cost1=val[id1];
        for (int f=0;f<=3;f++)
        if (IN(x[i]+dx[f],y[i]+dy[f]))
        {
            ll nx=x[i]+dx[f],ny=y[i]+dy[f];
            int id2=id[nx*mod+ny];
            int cost2;
            if (id2==0) cost2=1000000000; else cost2=val[id2];
            if (id2!=0) //走一步到达 
            {
                A.push_back(nod{id1,id2,cost1+cost2});
                continue;
            }
            for (int f2=0;f2<=3;f2++)
            if (IN(nx+dx[f2],ny+dy[f2]))
            {
                ll tx=nx+dx[f2],ty=ny+dy[f2];
                int id3=id[tx*mod+ty];
                if (id3==id1 || id3==0) continue;
                int cost3=val[id3];
                A.push_back(nod{id1,id3,max(cost1+cost2,cost2+cost3)});
            }
        }
    }
    for (int i=1;i<=tot+tot;i++) fa[i]=i;
    sort(A.begin(),A.end(),cmp);
    for (auto tt:A)
    {
        int x=tt.x,y=tt.y,v=tt.v;
        x=find(x); y=find(y);
        if (x==y) continue;
        tot++; edge[tot]+=x; edge[tot]+=y;
        fa[x]=fa[y]=tot; val[tot]=v;
    }
    tot++; 
    for (int i=1;i<=tot-1;i++) 
    if (find(i)==i)
    {
        edge[tot]+=i; val[tot]=2000000000;
    }
}

ll dp[maxn][505];
void MAX(ll &x,ll y) {x=max(x,y);}
void dfs(int x)
{
    dp[x][0]=0; if (siz[x]==1) dp[x][1]=0;
    for (int y:edge[x])
    {
        dfs(y);
        for (int l=siz[x];l>=0;l--)
        for (int r=min(siz[y],k-l);r>=0;r--)
        {
            MAX(dp[x][l+r],dp[x][l]+dp[y][r]+(ll)l*(ll)r*val[x]);
        }
        siz[x]+=siz[y]; if (siz[x]>=k) siz[x]=k;
    }
    return;
}
int main()
{
    init();
    assert(tot<=200000);
    dfs(tot);
    cout<<dp[tot][k]<<endl;
}