#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
const ll inf=1e18,mod=1e9+7;

int main(){
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int m,s,t;
    cin>>m>>s>>t;
    ll s1=0,s2=0,i=0;
    while(i<t){
        i++;s1+=17;
        if(m>=10) s2+=60,m-=10;
        else m+=4;
        if(s2>=s1) s1=s2;
        if(s1>=s){
            cout<<"Yes\n"<<i;
            return 0;
        }
    }
    cout<<"No\n"<<s1;
    return 0;
}