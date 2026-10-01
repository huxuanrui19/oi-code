#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
int n,a[N],pre[N],nxt[N],ans[N];
int main(){
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    stack<int> st;
    for(int i=1;i<=n;i++){
        while(!st.empty()&&a[st.top()]>=a[i]) st.pop();
        pre[i]=(st.empty())?0:st.top();
        st.push(i);
    }
    while(!st.empty()) st.pop();
    for(int i=n;i>=1;i--){
        while(!st.empty()&&a[st.top()]>=a[i]) st.pop();
        nxt[i]=(st.empty())?(n+1):st.top();
        st.push(i);
    }
    for(int i=1;i<=n;i++) ans[nxt[i]-pre[i]-1]=max(ans[nxt[i]-pre[i]-1],a[i]);
    for(int i=n;i>=1;i--) ans[i]=max(ans[i],ans[i+1]);
    for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
    return 0;
}