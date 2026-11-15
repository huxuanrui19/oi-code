#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+10,M=22;
const ll inf=1e18,mod=1e9+7;
int n,a[N],maxn[N],tree[N];
int lowbit(int x){
    return x&(-x);
}
void update(int pos,int x){
    while(pos<N){
        tree[pos]+=x;
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
map<vector<int>,int> mp;
int main(){
    freopen("ray.in","r",stdin);
    freopen("ray.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n;for(int i=1;i<=n;i++) cin>>a[i];
    if(n<=100){
        for(int t=1;t<=n*(n-1)/2;t++){
            vector<int> v;
            v.resize(n+1);
            for(int i=1;i<=n;i++)v[i]=a[i];
            int cnt=0;
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n-i;j++){
                    cnt++;
                    if(cnt==t){
                        if(v[j]<v[j+1]) swap(v[j],v[j+1]);
                    }
                    else if(v[j]>v[j+1]) swap(v[j],v[j+1]);
                }
            }
            mp[v]=1;
        }
        cout<<mp.size();
        return 0;
    }
    ll ans=0;
    if(n==2) cout<<1<<"\n";
    ans+=n-1;
    for(int i=1;i<=n;i++) maxn[i]=max(maxn[i-1],a[i]);
    for(int i=n;i>=1;i--){
        if(a[i]==n){}
        else if(query(n)-query(a[i])==0) ans++;
        else if(query(n)-query(a[i])==1&&maxn[i-1]<a[i]){
            ans++;
        }
        update(a[i],1);
    }
    if(n==3) ans--;
    cout<<ans;
    return 0;
}