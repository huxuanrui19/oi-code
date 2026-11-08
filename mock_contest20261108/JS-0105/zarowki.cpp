#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10,M=4e5+10;
const ll mod=1e9+7;
struct edge{
    int u,v;
}e[M];
int n,m,c[N];
unordered_map<ll,int> mp;
void dfs(int s){
    queue<ll> q;q.push(s);
    while(!q.empty()){
        ll mask=q.front();q.pop();mp[mask]=1;
        for(int i=1;i<=m;i++){
            int u=e[i].u,v=e[i].v;
            if(((mask>>(u-1))&1)==((mask>>(v-1))&1)){
                ll newmask=mask^(1<<(u-1))^(1<<(v-1));
                if(mp.count(newmask)) continue;
                q.push(newmask);
            }
        }
    }
}
inline ll qp(ll n,ll k){
    ll sum=1;
    while(k){
        if(k&1) sum=sum*n%mod;
        n=n*n%mod;
        k>>=1;
    }
    return sum;
}
int main(){
    freopen("zarowki.in","r",stdin);
    freopen("zarowki.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>c[i];
    for(int i=1;i<=m;i++) cin>>e[i].u>>e[i].v;
    if(m==0){
        cout<<"1";
        return 0;
    }
    int flag=0;
    for(int i=1;i<=m;i++){
        if(c[e[i].u]==c[e[i].v]) flag=1;
    }
    if(flag==0){
        cout<<"1";
        return 0;
    }
    if(n<=20&&m*(1<<n)<=1e8){
        ll mask=0;
        for(int i=1;i<=n;i++) mask|=((1<<(i-1))*c[i]);
        dfs(mask);
        cout<<mp.size();
        return 0;
    }
    cout<<qp(2,n-1);
    return 0;
}
