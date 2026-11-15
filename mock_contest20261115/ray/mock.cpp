#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
const ll inf=1e18,mod=1e9+7;
int a[11],b[11];
int main(){
    //freopen("ray.in","r",stdin);
    freopen("ray.in","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    for(int i=1;i<=10;i++) a[i]=b[i]=i;
    random_shuffle(b+1,b+11);
    int n=b[1];
    random_shuffle(a+1,a+n+1);
    cout<<n<<"\n";
    for(int i=1;i<=n;i++) cout<<a[i]<<" ";
    return 0;
}