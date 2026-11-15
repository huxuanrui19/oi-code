#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
const ll inf=1e18,mod=1e9+7;
int n,a[N];
map<vector<int>,int> mp;
int main(){
    freopen("ray.in","r",stdin);
    freopen("ans.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n;for(int i=1;i<=n;i++) cin>>a[i];
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