#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10;
const ll maxn=1e18,mod=1e9+7;
int n,a[N],b[N];
unordered_map<int,int> mp;
int main(){
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        ll num;cin>>num;
        mp[num]=i;
    }
    for(int i=1;i<=n;i++) b[i]=mp[a[i]];
    ll cnt=0,sum=0;
    for(int i=1;i<=n;i++){
        if(b[i]>b[i-1]) cnt++;
        else sum+=cnt*(cnt+1)/2,cnt=1;
    }
    sum+=cnt*(cnt+1)/2;
    cout<<sum;
    return 0;
}