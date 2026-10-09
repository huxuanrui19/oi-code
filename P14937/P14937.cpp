#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10,M=30;
const ll maxn=1e18,mod=1e9+7;
int n,m,ans,a[N],b[N];
bool check(int x){
    ll num=ans|(1<<x);
    ll cnt=0;
    if(((b[n]&num)!=0&&m%2==0)||(((b[n]&num)!=num)&&m%2==1)) return 0;
    for(int i=1;i<=n;i++){
        if(cnt%2==0){
            if((b[i]&num)==num) cnt++;
        }
        else if((b[i]&num)==0) cnt++;
    }
    return cnt>=m;
}
int main(){
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t;cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++) b[i]=b[i-1]^a[i];
        ans=0;
        for(int i=M-1;i>=0;i--){
            if(check(i)) ans|=(1<<i);
        }
        cout<<ans<<"\n";
    }
    return 0;
}