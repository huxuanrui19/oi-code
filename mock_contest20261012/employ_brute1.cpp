#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=500+10;
const ll mod=998244353;
int n,m,c[N],pre[N];
string s;
int main(){
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    cin>>s;s=" "+s;
    for(int i=1;i<=n;i++) cin>>c[i];
    for(int i=1;i<=n;i++) pre[i]=i;
    ll ans=0;
    do{
        int a,b;a=b=0;
        for(int i=1;i<=n;i++){
            if(s[i]=='0') b++;
            else if(b>=c[pre[i]]) b++;
            else a++;
        }
        if(a>=m) ans++;
    }while(next_permutation(pre+1,pre+n+1));
    cout<<ans;
    return 0;
}