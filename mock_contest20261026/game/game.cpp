#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+10;
const ll mod=1.5e9+1,base=211;
ll n,ans=0;
string s;
bool check(int l,int r){
    stack<char> st;
    for(int i=l;i<=r;i++){
        if(st.empty()) st.push(s[i]);
        else if(st.top()!=s[i]) st.push(s[i]);
        else if(st.top()==s[i]) st.pop();
        if(st.size()>(r-i)) return 0;
    }
    if(st.empty()) return 1;
    return 0;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>s;
    s=' '+s;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if((j-i+1)%2) continue;
            if(check(i,j)) ans++;
        }
    }
    cout<<ans;
    return 0;
}
