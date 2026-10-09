#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10,M=2e7+10;
const ll maxn=1e18,mod=1e9+7;
int n;
ll a[N];int sum[M];
struct sta{
    int siz;
    pair<int,int> stk[M];
    inline void push(int num,int cnt){stk[++siz]={num,cnt};}
    inline void pop(){stk[siz--]={0,0};}
    inline pair<int,int> top(){return stk[siz];}
    inline bool empty(){return siz==0;}
    inline void update(int num){stk[siz].second=num;}
}st;
void init(){
    ll x,y,z,m0,m1,c0,c1;
    cin>>x>>y>>z>>m0>>m1>>c0>>c1;
    a[0]=c0;a[1]=c1;
    for(int i=2;i<n;i++) a[i]=(a[i-1]*x+a[i-2]*y+z)%(i%2==0?m0:m1)+1;
    return;
}
int main(){
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    init();string s;
    for(int i=0;i<n;i++){
        for(int j=1;j<=a[i];j++) s+=(i%2==0?"(":")");
    }
    cerr<<s<<"\n";
    for(int i=0;i<(int)s.size();i++){
        if(s[i]=='(') sum[i]++;
        else sum[i]--;
    }
    for(int i=1;i<(int)s.size();i++) sum[i]+=sum[i-1];
    st.siz=0;st.push(0,1);ll ans=0;
    for(int i=0;i<(int)s.size();i++){
        while(!st.empty()&&st.top().first>sum[i]){
            ans+=st.top().second*(st.top().second-1)/2;
            st.pop();
        }
        if(st.empty()) st.push(sum[i],1);
        else if(st.top().first==sum[i]){
            int cnt=st.top().second+1;
            st.update(cnt);
        }
        else st.push(sum[i],1);
    }
    while(!st.empty()){
        ans+=(st.top().second-1)*st.top().second/2;
        st.pop();
    }
    cout<<ans;
    return 0;
}