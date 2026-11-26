#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3e5+10;
const ll inf=1e18,mod=1e9+7;
ll n,k,b[N];
int main(){
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>b[i];
    queue<pair<int,ll> > q;
    ll ans=0,sum=0,tot=0;
    for(ll i=n;i>=1;i--){
        sum-=tot;
        while(!q.empty()&&q.front().first>i) tot-=q.front().second,q.pop();
        b[i]-=sum;
        if(b[i]<=0) continue;
        else{
            ll minn=min(k,i);
            ans+=b[i]/minn+(b[i]%minn!=0);
            sum+=(b[i]/minn+(b[i]%minn!=0))*minn;
            tot+=(b[i]/minn+(b[i]%minn!=0));
            ll pos=i-minn+1;
            q.push({pos,b[i]/minn+(b[i]%minn!=0)});
        }
    }
    cout<<ans;
    return 0;
}
