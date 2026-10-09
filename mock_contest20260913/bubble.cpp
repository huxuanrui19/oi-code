#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
const ll maxn=1e18,mod=1e9+7;
int n,k,a[N],b[N],c[N];
int main(){
    freopen("bubble.in","r",stdin);
    freopen("bubble.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    int maxn=-1,cnt=0;
    for(int i=1;i<=n;i++){
        if(maxn>a[i]) b[i+k]=a[i];
        else c[++cnt]=a[i];
        maxn=max(maxn,a[i]);
    }
    cnt=1;
    for(int i=1;i<=n;i++){
        if(b[i]) cout<<b[i]<<" ";
        else{
            cout<<c[cnt++]<<" ";
        }
    }
    return 0;
}