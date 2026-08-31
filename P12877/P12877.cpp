#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
ll n,a[N],b[N],s[N<<1],t[N],nxt[N];
int main(){
    //freopen(".in","r",stdin);
    //freopen(".out","r",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    if(n==1){
        cout<<0;
        return 0;
    }
    for(int i=0;i<n-1;i++) s[i]=a[i+1]-a[i];
    s[n-1]=a[0]-a[n-1];
    for(int i=0;i<n-1;i++) t[i]=b[i+1]-b[i];
    t[n-1]=b[0]-b[n-1];
    nxt[0]=0;
    for(int i=1;i<n;i++){
        int j=nxt[i-1];
        while(j&&t[i]!=t[j]) j=nxt[j-1];
        if(t[i]==t[j]) nxt[i]=j+1;
        else nxt[i]=0;
    }
    for(int i=0;i<n-1;i++) s[i+n]=s[i];
    for(int i=0,j=0;i<=2*n-1;){
        if(s[i]==t[j]){
            i++;j++;
            if(j==n){
                cout<<(i-n);
                return 0;
            }
        }
        else{
            if(j==0) i++;
            else j=nxt[j-1];
        }
    }
    cout<<"-1";
    return 0;
}