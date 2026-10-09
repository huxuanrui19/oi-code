#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e7+10;
const ll maxn=1e18,mod=1e9+7;
int n;ll a[N],e[N];
void init(){
    ll x,y,z,m0,m1,c0,c1;
    cin>>x>>y>>z>>m0>>m1>>c0>>c1;
    a[0]=c0;a[1]=c1;
    for(int i=2;i<n;i++) a[i]=(a[i-1]*x+a[i-2]*y+z)%(i%2==0?m0:m1)+1;
    return;
}
struct sta{
    int siz;
    pair<int,int> stk[N];
    inline void push(int num,int cnt){stk[++siz]={num,cnt};}
    inline void pop(){stk[siz--]={0,0};}
    inline pair<int,int> top(){return stk[siz];}
    inline bool empty(){return siz==0;}
    inline void update(int num){stk[siz].second=num;}
}st;
int main(){
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n;init();
    ll ans=0;st.siz=0;
    for(int i=0;i<n;i++){
        if(i%2==0){st.push(i,a[i]);continue;}
        ll need=a[i];
        ll lst=0;
        while(need>0&&!st.empty()){
            ll rem=st.top().second;
            ll d=min(rem,need);
            rem-=d;need-=d;
            if(rem==0){
                ans=ans+(d-1);
                ll val=1;
                if(st.top().first>=1) val=val+e[st.top().first-1];
                ans+=val;
                lst=val;
                st.pop();
            }
            else{
                ans+=d;lst=1;
                st.update(rem);
            }
        }
        if(need>0) lst=0;
        e[i]=lst;
    }
    cout<<ans;
    return 0;
}