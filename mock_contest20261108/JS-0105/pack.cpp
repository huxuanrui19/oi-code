#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
ll n,l,a[N],ans[N];
int main(){
    freopen("pack.in","r",stdin);
    freopen("pack.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>l;
    for(int i=1;i<=n;i++) cin>>a[i];
    ll res=l;ans[n+1]=1;
    for(int i=n;i>=1;i--){
        if(res>=a[i]){
            ans[i]=ans[i+1];
            res-=a[i];
        }
        else res=l-a[i],ans[i]=ans[i+1]+1;
    }
    for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
    return 0;
}
