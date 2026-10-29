#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+10;
const ll mod=1.5e9+1,base=211;
ll n,ans=0;
string s;
ll check(int l){
    stack<char> st;int cnt=0;
    for(int i=l;i<=n;i++){
        if(st.empty()) st.push(s[i]);
        else if(st.top()!=s[i]) st.push(s[i]);
        else if(st.top()==s[i]) st.pop();
        if(st.size()==0) cnt++;
    }
    return cnt;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>s;
    s=' '+s;
    for(int i=1;i<=n;i++){
        ans+=check(i);
    }
    cout<<ans;
    return 0;
}
