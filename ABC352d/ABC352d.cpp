#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
int p[N],a[N],maxn[N],minn[N];
int main(){
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,k;cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>p[i];
    for(int i=1;i<=n;i++) a[p[i]]=i;
    deque<int> q;int ans=1e9;
    for(int i=1;i<=n;i++){
        while(!q.empty()&&(i-q.front()+1)>k) q.pop_front();
        while(!q.empty()&&a[q.back()]>a[i]) q.pop_back();
        q.push_back(i);
        minn[i]=a[q.front()];
    }
    q.clear();
    for(int i=1;i<=n;i++){
        while(!q.empty()&&(i-q.front()+1)>k) q.pop_front();
        while(!q.empty()&&a[q.back()]<a[i]) q.pop_back();
        q.push_back(i);
        maxn[i]=a[q.front()];
    }
    for(int i=k;i<=n;i++) ans=min(maxn[i]-minn[i],ans);
    cout<<ans;
    return 0;
}