#include <bits/stdc++.h>
#define lowbit(x) (x)&-(x)
using namespace std;
typedef long long ll;
const int N=1e6+10,M=2e6+10;
const ll maxn=1e18,mod=1e9+7;
int n,q,a[M];
int tree[M];
void update(int pos){
    while(pos<M){
        tree[pos]++;
        pos+=lowbit(pos);
    }
}
ll query(int pos){
    ll ans=0;
    while(pos){
        ans+=tree[pos];
        pos-=lowbit(pos);
    }
    return ans;
}
int main(){
    freopen("love.in","r",stdin);
    freopen("love.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n>>q;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) update(a[i]+i);
    for(int i=n;i<M;i++){
        a[i]=query(M-1)-query(i-1);
        update(a[i]+i);
    }
    for(int i=1;i<=q;i++){
        int k;cin>>k;
        cout<<a[k]<<"\n";
    }
    return 0;
}