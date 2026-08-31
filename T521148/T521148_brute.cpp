#include <bits/stdc++.h>
#define pii pair<ll,int>
using namespace std;
typedef long long ll;
const int N=1e5+10;
ll n,m,a[N];
struct comp{
    bool operator() (int x1,int x2)const{
        if(a[x1]!=a[x2]) return a[x1]>a[x2];
        else return x1>x2;
    }
};
set<int,comp> s;
int main(){
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    a[0]=a[n+1]=-1;
    for(int i=1;i<=n;i++){
        if(a[i-1]>=a[i]&&a[i+1]>=a[i]) s.insert(i);
    }
    while(!s.empty()){
        int i=*s.begin();s.erase(s.begin());
        ll num=min(a[i-1],a[i+1])-a[i]+1;
        a[i]+=min(m,num);m-=min(m,num);
        if(m==0) break;
        if(a[i-2]>=a[i-1]&&a[i]>=a[i-1]) s.insert(i-1);
        if(a[i]>=a[i+1]&&a[i+2]>=a[i+1]) s.insert(i+1);
    }
    ll ans=0;
    for(int i=1;i<=n;i++) ans=max(ans,a[i]);
    cout<<ans;
    return 0;
}