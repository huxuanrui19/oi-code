#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
const ll base1=131,mod=1e9+7;
const ll base2=37,mod=1e9+9;
int n,q;
struct node{
    string s1,s2;
    vector<ll> h11,h12;
    vector<ll> h21,h22;
}a[N];
int main(){
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>a[i].s1>>a[i].s2;
    for(int i=1;i<=n;i++){
        a[i].init();
    }
    return 0;
}