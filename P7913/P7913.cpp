#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
int n,m1,m2,cnt1,cnt2;
struct node{
    int a,type,idx;
    bool operator<(const node &x)const{
        return a<x.a;
    }
}a1[N<<1],a2[N<<1];
int b1[N],b2[N],sum1[N],sum2[N];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m1>>m2;
    for(int i=1;i<=m1;i++){
        int a,b;cin>>a>>b;
        a1[++cnt1]={a,1,i};
        a1[++cnt1]={b,-1,i};
    }
    for(int i=1;i<=m2;i++){
        int a,b;cin>>a>>b;
        a2[++cnt2]={a,1,i};
        a2[++cnt2]={b,-1,i};
    }
    sort(a1+1,a1+cnt1+1);
    sort(a2+1,a2+cnt2+1);
    priority_queue<int,vector<int>,greater<int> > q;
    for(int i=1;i<=n;i++) q.push(i);
    for(int i=1;i<=cnt1;i++){
        if(a1[i].type==1){
            if(q.empty()){
                b1[a1[i].idx]=n+1;
            }
            else b1[a1[i].idx]=q.top(),q.pop();
        }
        else{
            if(b1[a1[i].idx]!=n+1){
                q.push(b1[a1[i].idx]);
            }
        }
    }
    while(!q.empty()) q.pop();
    for(int i=1;i<=n;i++) q.push(i);
    for(int i=1;i<=cnt2;i++){
        if(a2[i].type==1){
            if(q.empty()){
                b2[a2[i].idx]=n+1;
            }
            else b2[a2[i].idx]=q.top(),q.pop();
        }
        else{
            if(b2[a2[i].idx]!=n+1){
                q.push(b2[a2[i].idx]);
            }
        }
    }
    for(int i=1;i<=m1;i++) sum1[b1[i]]++;
    for(int i=1;i<=m2;i++) sum2[b2[i]]++;
    for(int i=1;i<=n;i++) sum1[i]+=sum1[i-1];
    for(int i=1;i<=n;i++) sum2[i]+=sum2[i-1];
    int ans=0;
    for(int i=0;i<=n;i++) ans=max(ans,sum1[i]+sum2[n-i]);
    cout<<ans;
    return 0;
}
