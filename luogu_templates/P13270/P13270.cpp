#include<bits/stdc++.h>
#ifdef LOCAL
#define debug(x) cerr<<x<<" "
#else
#define debug(x)
#endif

using namespace std;
typedef long long ll;
const int N=1e5+10;
int n;string s;
int get_min(string s){
    s.resize(2*n);
    s=" "+s;
    for(int i=1;i<=n;i++) s[i+n]=s[i];
    int i=1,j=2,k=0;
    while(i<=n&&j<=n){
        while(k<n&&s[i+k]==s[j+k]) k++;
        if(s[i+k]>s[j+k]) i=i+k+1;
        else j=j+k+1;
        if(i==j) j++;
        k=0;
    }
    return min(i,j);
}
int main(){
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);cerr.tie(0);
    cin>>n>>s;
    int sta=get_min(s);
    for(int i=1,j;i<=n;i++){
        j=(sta+i-1)>n?(sta+i-1-n):(sta+i-1);
        cout<<s[j-1];
    }
    return 0;
}