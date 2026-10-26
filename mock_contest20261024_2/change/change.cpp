#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
const int N=1e5+10;
const ll maxn=1e18,mod=1e9+7;
int n,ans,num10,num20,a[N];
int main(){
    //freopen("change.in","r",stdin);
    //freopen("change.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    priority_queue<pii,vector<pii>,less<pii> > q;
    for(int i=1;i<=n;i++){
        if(a[i]==10) num10++,ans++;
        else if(a[i]==20){
            if(num10) num20++,num10--,ans++;
            else{
                if(!q.empty()&&q.top().first){
                    ans--;
                    num10+=q.top().first;
                    num20+=q.top().second;
                    q.pop();
                }
                if(num10) ans++,num20++,num10--;
            }
        }
        else if(a[i]==50){
            if(num20>=2) num20-=2,ans++,q.push({0,2});
            else if(num20==1&&num10>=2) num10-=2,num20--,ans++,q.push({2,1});
            else if(num10>=4) num10-=4,ans++,q.push({4,0});
        }
    }
    cout<<ans;
    return 0;
}
