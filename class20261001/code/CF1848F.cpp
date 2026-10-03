#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+5;
int n,k;
int a[maxn],b[maxn];
int main(){
    ios::sync_with_stdio(0);
    cin>>n;k=log2(n);
    bool flg=1;
    for(int i=0;i<n;i++)cin>>a[i],flg&=(a[i]==0);
    if(flg){
        cout<<0<<endl;
        return 0;
    }
    int ans=0;
    for(int j=k-1;j>=0;j--){
        for(int i=0;i<n;i++)b[i]=a[i]^a[(i+(1<<j))%n];
        bool flag=1;
        for(int i=0;i<n;i++)flag&=(b[i]==0);
        if(!flag){
            for(int i=0;i<n;i++)a[i]=b[i];
            ans+=(1<<j);
        }
    }
    cout<<ans+1<<endl;
    return 0;
}