#include <bits/stdc++.h>
#define pii pair<ll,int>
using namespace std;
typedef long long ll;
const int N=6e5+10;
const ll maxn=1e18,mod=1e9+7;
ll n,m,k[N],lev[N];
vector<int> a[N];
priority_queue<pii,vector<pii>,greater<pii> > q;
int main(){
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>k[i];
        a[i].resize(k[i]+1);
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        q.push({a[i][1],i});
    }
    ll sum=0,ans=0,t=0;
    while(!q.empty()){
        int u=q.top().second;q.pop();
        lev[u]++;
        ans+=sum*a[u][lev[u]];
        sum++;
        t+=a[u][lev[u]];
        if(lev[u]<k[u]) q.push({a[u][lev[u]+1],u});
    }
    cout<<(m-t)*sum+ans;
    return 0;
}