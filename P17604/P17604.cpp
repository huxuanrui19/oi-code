#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10,M=500;
const ll inf=1e18,mod=1e9+7;
ll n,m,ans[N];
struct ScanLine{
    ll yi,leftx,rightx,inout;
    ScanLine(){}
    ScanLine(ll y,ll x1,ll x2,ll io):
        yi(y),leftx(x1),rightx(x2),inout(io){}
    bool operator <(const ScanLine &x) const{
        return yi<x.yi;
    }
}line[N<<1];
ll cnt,xpos[N<<1],c[N<<1],lst[N<<1];
int main(){
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int xi,yi;cin>>xi>>yi;
        line[++cnt]={yi,xi,xi+m,1};
        xpos[cnt]=xi;
        line[++cnt]={yi+m,xi,xi+m,-1};
        xpos[cnt]=xi+m;
    }
    sort(line+1,line+cnt+1);
    sort(xpos+1,xpos+cnt+1);
    int num=unique(xpos+1,xpos+cnt+1)-xpos-1;
    for(int i=1;i<=cnt;i++){
        int l=lower_bound(xpos+1,xpos+num+1,line[i].leftx)-xpos;
        int r=lower_bound(xpos+1,xpos+num+1,line[i].rightx)-xpos;
        for(int xx=l;xx<r;xx++){
            ans[c[xx]]+=(line[i].yi-line[lst[xx]].yi)*(xpos[xx+1]-xpos[xx]);
            c[xx]+=line[i].inout;lst[xx]=i;
        }
    }
    for(int i=1;i<=n;i++) cout<<ans[i]<<"\n";
    return 0;
}