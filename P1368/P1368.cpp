#include<bits/stdc++.h>
#ifdef LOCAL
#define debug(x) cerr<<x<<" "
#else
#define debug(x)
#endif

using namespace std;
typedef long long ll;
const int N=3e5+10;
int n,a[N<<1];
int get_min(int a[]){
    for(int i=1;i<=n;i++) a[i+n]=a[i];
    int i=1,j=2,k=0;
    while(i<=n&&j<=n){
        while(k<n&&a[i+k]==a[j+k]) k++;
        if(a[i+k]>a[j+k]) i=i+k+1;
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
    cin>>n;for(int i=1;i<=n;i++) cin>>a[i];
    int sta=get_min(a);debug(sta);
    for(int i=1,j;i<=n;i++){
        j=(sta+i-1)>n?(sta+i-1-n):(sta+i-1);
        cout<<a[j]<<" ";
    }
    return 0;
}