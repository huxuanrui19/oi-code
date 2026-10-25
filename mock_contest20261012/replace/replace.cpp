#include <bits/stdc++.h>
#define pii pair<ll,ll>
using namespace std;
typedef long long ll;
const int N=2e5+10,M=2.5e6+10;
const ll base=211,mod=1568873333;
string s1[N],s2[N];
int n,q;
struct node{
    string pre1,pre2;
};
map<pii,vector<node> > mp;
ll get_hash(string s){
    ll num=0;
    for(int i=0;i<(int)s.size();i++){
        num=num*10%mod;
        num=(num+s[i]-'a')%mod;
    }
    return num;
}
void init(){
    for(int i=1;i<=n;i++){
        if(s1[i]==s2[i]) continue;
        else{
            int l=-1,r=-1;
            for(int j=0;j<(int)s1[i].size();j++){
                if(s1[i][j]!=s2[i][j]){
                    l=j;break;
                }
            }
            for(int j=s1[i].size()-1;j>=0;j--){
                if(s1[i][j]!=s2[i][j]){
                    r=j;break;
                }
            }
            if(l<0) continue;
            string suf=s1[i].substr(0,l);
            string pre=s1[i].substr(r+1);
            ll key=0;
        }
    }
}
int tree1[M][26],tree2[M][26];
int n1,n2,cnt2[M];
void insert1(int u){
    //
}
void insert2(int u){
    //
}
void undo(int u){
    //
}
int main(){
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>s1[i]>>s2[i];
    init();
    while(q--){
        string t1,t2;
        cin>>t1>>t2;
        int l=0,r=0;
        if(t1.size()!=t2.size()){
            cout<<"0\n";continue;
        }
        for(int i=0;i<(int)t1.size();i++){
            if(t1[i]!=t2[i]){
                l=i;break;
            }
        }
        for(int i=t1.size()-1;i>=0;i--){
            if(t1[i]!=t2[i]){
                r=i;break;
            }
        }
        ll core1=get_hash(t1.substr(l,r-l+1));
        ll core2=get_hash(t2.substr(l,r-l+1));
        ll ans=0;
        for(auto d:mp[make_pair(core1,core2)]){
            if(l<(int)d.pre1.size()) continue;
            if(t1.size()-r-1<d.pre2.size()) continue;
            string p=t1.substr(l-d.pre1.size(),d.pre1.size());
            string s=t1.substr(r+1,d.pre2.size());
            if(p==d.pre1&&s==d.pre2) ans++;
        }
        cout<<ans<<"\n";
    }
    return 0;
}