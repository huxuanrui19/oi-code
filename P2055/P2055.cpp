#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=50+10;
const ll inf=1e18,mod=1e9+7;
int n,l,r,ans=0,vis[N],flag[N],match[N];
vector<int> v1,v2;
vector<int> g[N];
bool find(int u){
    for(auto d:g[u]){
        if(vis[d]==0){
            if(flag[d]) continue;
            flag[d]=1;
            if((!match[d])||find(match[d])){
                match[d]=u;
                return 1;
            }
        }
    }
    return 0;
}
void hungary(){
    for(auto d:v2){
        memset(flag,0,sizeof(flag));
        if(find(d)) ans++;
    }
}
int main(){
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t;cin>>t;
    while(t--){
        cin>>n;
        l=r=0;
        for(int i=1;i<=n;i++){
            cin>>vis[i];
            if(vis[i]==0) l++,v1.push_back(i);
        }
        for(int i=1;i<=n;i++){
            int num;cin>>num;
            if(vis[i]==1&&num==0){
                vis[i]=0,l++,v1.push_back(i);
                r++;v2.push_back(i);
                g[i].push_back(i);
            }
            else if(vis[i]==1&&num==1){
                vis[i]=1,r++,v2.push_back(i);
                g[i].push_back(i);
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                int num;cin>>num;
                if(num) g[i].push_back(j);
            }
        }
        ans=0;
        hungary();
        if(ans>=l) cout<<"^_^\n";
        else cout<<"T_T\n";
        v2.clear();v1.clear();
        for(int i=1;i<=n;i++) g[i].clear();
        for(int i=1;i<=n;i++) match[i]=vis[i]=0;
    }
    return 0;
}