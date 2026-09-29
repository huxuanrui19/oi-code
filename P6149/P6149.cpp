#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
const ll mod=1e9+7;
int n;
ll xlen,ylen,xlis[N],ylis[N];
struct node{
    ll x,y;
}a[N];
vector<ll> vx[N],xsum[N];
vector<ll> vy[N],ysum[N];
int main(){
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].x>>a[i].y;
        xlis[i]=a[i].x;ylis[i]=a[i].y;
    }
    sort(xlis+1,xlis+n+1);
    sort(ylis+1,ylis+n+1);
    xlen=unique(xlis+1,xlis+n+1)-xlis-1;
    ylen=unique(ylis+1,ylis+n+1)-ylis-1;
    for(int i=1;i<=n;i++){
        int xpos=lower_bound(xlis+1,xlis+xlen+1,a[i].x)-xlis;
        int ypos=lower_bound(ylis+1,ylis+ylen+1,a[i].y)-ylis;
        vx[xpos].push_back(a[i].y);
        vy[ypos].push_back(a[i].x);
    }
    for(int i=1;i<=xlen;i++) sort(vx[i].begin(),vx[i].end());
    for(int i=1;i<=ylen;i++) sort(vy[i].begin(),vy[i].end());
    for(int i=1;i<=xlen;i++){
        xsum[i].resize(vx[i].size());
        for(int j=0;j<vx[i].size();j++){
            if(j==0) xsum[i][j]=vx[i][j];
            else xsum[i][j]=(xsum[i][j-1]+vx[i][j])%mod;
        }
    }
    for(int i=1;i<=ylen;i++){
        ysum[i].resize(vy[i].size());
        for(int j=0;j<vy[i].size();j++){
            if(j==0) ysum[i][j]=vy[i][j];
            else ysum[i][j]=(ysum[i][j-1]+vy[i][j])%mod;
        }
    }
    ll ans=0;
    for(int i=1;i<=n;i++){
        int xpos=lower_bound(xlis+1,xlis+xlen+1,a[i].x)-xlis;
        int ypos=lower_bound(ylis+1,ylis+ylen+1,a[i].y)-ylis;
        int xid=lower_bound(vy[ypos].begin(),vy[ypos].end(),a[i].x)-vy[ypos].begin();
        int yid=lower_bound(vx[xpos].begin(),vx[xpos].end(),a[i].y)-vx[xpos].begin();
        ll Sy=(yid+1)*a[i].y-xsum[xpos][yid]+xsum[xpos][vx[xpos].size()-1]-xsum[xpos][yid]-(vx[xpos].size()-1-yid)*a[i].y;
        ll Sx=(xid+1)*a[i].x-ysum[ypos][xid]+ysum[ypos][vy[ypos].size()-1]-ysum[ypos][xid]-(vy[ypos].size()-1-xid)*a[i].x;
        Sy=(Sy%mod+mod)%mod;
        Sx=(Sx%mod+mod)%mod;
        ans=(ans+Sy*Sx%mod)%mod;
    }
    cout<<ans;
    return 0;
}