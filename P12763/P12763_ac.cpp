#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
const ll inf=1e18,mod=1e9+7;
ll n,s,a[N];
int main(){
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n>>s;for(int i=1;i<=n;i++) cin>>a[i];
    unordered_map<int,vector<int> > mp;
    queue<int> q;
    unordered_map<int,int> cnt;
    for(int i=1;i<=n;i++){
        cnt[(a[i]+1)%s]++;
        mp[(a[i]+1)%s].push_back({i});
    }
    ll cur=0,sum=0;
    priority_queue<pair<int,int> > pq;
    for(auto &d:cnt) pq.push({d.second,d.first});
    while(!pq.empty()){
        if(cur==s-1) cur=0,sum++;
        auto d=pq.top();pq.pop();
        int num=d.second;
        if(num!=s-1-cur||pq.empty()){
            cur=(cur+num)%s;
            q.push(mp[num].back());mp[num].pop_back();
            d.first--;
            if(d.first) pq.push(d);
        }
        else{
            auto t=pq.top();pq.pop();pq.push(d);
            cur=(cur+t.second)%s;
            q.push(mp[t.second].back());mp[t.second].pop_back();
            t.first--;
            if(t.first) pq.push(t);
        }
    }
    cout<<sum<<"\n";
    while(!q.empty()){
        cout<<q.front()<<" ";q.pop();
    }
    return 0;
}