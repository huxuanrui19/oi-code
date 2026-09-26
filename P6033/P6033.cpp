#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e7+10,M=1e5+10;
ll n,a[N],b[M];
int main(){
    //freopen(".in","r",stdin);
    //freopen(".out","r",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) b[a[i]]++;
    int cur=0;
    for(int i=1;i<=n;i++){
        while(b[cur]==0) cur++;
        a[i]=cur;b[cur]--;
    }
    int num=0,pos=1;ll ans=0;
    deque<ll> q;
    while(num<n-1){
        ll cnt1=0,cnt2=0;
        if(q.empty()||(a[pos]<q.front()&&pos<=n)) cnt1=a[pos++];
        else cnt1=q.front(),q.pop_front();
        if(q.empty()||(a[pos]<q.front()&&pos<=n)) cnt2=a[pos++];
        else cnt2=q.front(),q.pop_front();
        num++;ans+=cnt1+cnt2;
        q.push_back(cnt1+cnt2);
    }
    cout<<ans;
    return 0;
}