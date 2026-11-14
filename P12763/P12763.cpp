#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
int n,s,a[N];
struct node{
    int num,idx;
    bool operator <(const node &x) const{
        return num<x.num;
    }
}b[N];
int main(){
    //freopen("/Users/jerry/code_cpp_hxr/oi-code/P12763/ex/tom3ocen.in","r",stdin);
    //freopen(".out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>s;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) b[i]={(a[i]+1)%s,i};
    sort(b+1,b+n+1);
    ll ans=0,lst=0;
    for(int i=1;i<=n;i++){
        if(lst==s-1) ans++,lst=b[i].num;
        else lst=(lst+b[i].num)%s;
    }
    cout<<ans<<"\n";
    for(int i=1;i<=n;i++) cout<<b[i].idx<<" ";
    return 0;
}