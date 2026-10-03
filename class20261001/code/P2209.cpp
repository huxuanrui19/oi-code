#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+5;
typedef long long ll;
int n,G,B,D;
struct node{
    int x,y;
}a[maxn];
inline bool cmp(node a,node b){
    return a.x<b.x;
}
pair<int,int>q[maxn];
int hd,tl;
int main(){
    ios::sync_with_stdio(0);
    cin>>n>>G>>B>>D;
    for(int i=1;i<=n;i++)cin>>a[i].x>>a[i].y;
    sort(a+1,a+n+1,cmp);
    ll ans=0;
    q[hd=tl=1]=make_pair(B,0);
    int now=B;
    a[n+1].x=D;
    for(int i=1;i<=n+1;i++){
        int need=a[i].x-a[i-1].x;
        if(now<need){
            cout<<-1<<endl;
            return 0;
        }
        while(hd<=tl&&need){
            ans+=1ll*min(need,q[hd].first)*q[hd].second;
            if(need<=q[hd].first){
                q[hd].first-=need;
                now-=need;                                      
                need=0;
            }
            else{
                need-=q[hd].first;
                now-=q[hd].first;
                hd++;
            }
        }
        while(hd<=tl&&q[tl].second>=a[i].y){
            now-=q[tl].first;
            tl--;
        }
        q[++tl]=make_pair(G-now,a[i].y);
        now=G;
    } 
    cout<<ans<<endl;
}