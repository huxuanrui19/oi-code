#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
int n,q;
string s1[N],s2[N];
int main(){
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>s1[i]>>s2[i];
    while(q--){
        string t1,t2;cin>>t1>>t2;
        if(t1.size()!=t2.size()){
            cout<<"0\n";continue;
        }
        ll ans=0;
        for(int i=1;i<=n;i++){
            int len=s1[i].size();
            for(int j=0;j+len<=(int)t1.size();j++){
                if(t1.substr(j,len)!=s1[i]) continue;
                string r=t1.substr(0,j)+s2[i]+t1.substr(j+len);
                if(r==t2) ans++;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}