#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+5;
int q[maxn],hd,tl;
int n,k;
int p[maxn],mx[maxn],mn[maxn],a[maxn];
const int inf=1e9;
int main(){
    ios::sync_with_stdio(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>p[i],a[p[i]]=i;
    hd=1;tl=0;
    for(int i=1;i<=n;i++){
        while(hd<=tl&&q[hd]+k<=i)hd++;
        while(hd<=tl&&a[q[tl]]<=a[i])tl--;
        q[++tl]=i;
        mx[i]=a[q[hd]];
    }
    hd=1;tl=0;
    for(int i=1;i<=n;i++){
        while(hd<=tl&&q[hd]+k<=i)hd++;
        while(hd<=tl&&a[q[tl]]>=a[i])tl--;
        q[++tl]=i;
        mn[i]=a[q[hd]];
    }
    int res=inf;
    for(int i=k;i<=n;i++)res=min(res,mx[i]-mn[i]);
    printf("%d\n",res);
    return 0;
}