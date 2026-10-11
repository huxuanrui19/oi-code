#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3e5+10;
const ll maxn=1e18,mod=1e9+7;
string s;
deque<int> bpos;
int flag[N];
int main(){
    freopen("erase.in","r",stdin);
    freopen("erase.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>s;
    for(int i=0;i<(int)s.size();i++){
        if(s[i]=='B') bpos.push_back(i);
    }
    ll ans=0;
    for(int i=0;i<(int)s.size();i++){
        if(s[i]=='C'){
            if(!bpos.empty()){
                if(bpos.front()>i) continue;
                bpos.pop_front();
                ans++;
            }
        }
    }
    for(int i=0;i<(int)s.size();i++){
        if(s[i]=='A'){
            while(!bpos.empty()&&bpos.front()<i) bpos.pop_front();
            if(!bpos.empty()){
                bpos.pop_front();
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}