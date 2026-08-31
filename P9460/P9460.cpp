#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10;
int n,k,cnt,a[N],sum[N];
bool cal(int pos){
    int num=a[pos]+k;
    int t=lower_bound(a+1,a+pos,num,greater<int>())-(a+1);
    ll tot=sum[t]-1LL*t*num;
    return tot<=k;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>k;
    for(int i=1,num;i<=n;i++){
        cin>>num;
        a[num]++;
    }
    sort(a+1,a+n+1,greater<int>());
    for(cnt=1;cnt<=n+1;cnt++){
        if(a[cnt]==0) break;
    }
    for(int i=1;i<=cnt;i++) sum[i]=sum[i-1]+a[i];
    if(cal(cnt)){
        cout<<"pigstd";
        return 0;
    }
    int ans=0;
    for(int i=1;i<cnt;i++){
        if(cal(i))ans++;
    }
    cout<<ans;
    return 0;
}
