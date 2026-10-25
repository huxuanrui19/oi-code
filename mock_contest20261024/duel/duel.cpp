#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
const ll inf=1e18,mod=1e9+7;
int n,ans,a[N];
int main(){
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    for(int i=1,num;i<=n;i++) cin>>num,a[num]++;
    for(int i=1;i<N;i++) ans=max(ans,a[i]);
    cout<<ans;
    return 0;
}