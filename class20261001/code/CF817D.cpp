#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e6+5;
int n;
int a[maxn];
int pre[maxn],suf[maxn];
ll sum_pre[maxn];
ll solve_max(int L,int R){
    if(L==R)return a[L];
    int mid=(L+R)/2;
    ll res=solve_max(L,mid)+solve_max(mid+1,R);
    suf[mid]=a[mid];for(int i=mid-1;i>=L;i--)suf[i]=max(suf[i+1],a[i]);
    pre[mid+1]=a[mid+1];for(int i=mid+2;i<=R;i++)pre[i]=max(pre[i-1],a[i]);
    int j=mid+1;
    sum_pre[R+1]=0;
    for(int i=R;i>=mid;i--)sum_pre[i]=sum_pre[i+1]+pre[i];
    for(int i=mid;i>=L;i--){
        while(j<=R&&pre[j]<=suf[i])j++;
        res+=1ll*suf[i]*(j-mid-1);
        res+=sum_pre[j];
    }
    return res;
}
ll solve_min(int L,int R){
    if(L==R)return a[L];
    int mid=(L+R)/2;
    ll res=solve_min(L,mid)+solve_min(mid+1,R);
    suf[mid]=a[mid];for(int i=mid-1;i>=L;i--)suf[i]=min(suf[i+1],a[i]);
    pre[mid+1]=a[mid+1];for(int i=mid+2;i<=R;i++)pre[i]=min(pre[i-1],a[i]);
    int j=mid+1;
    sum_pre[R+1]=0;
    for(int i=R;i>=mid;i--)sum_pre[i]=sum_pre[i+1]+pre[i];
    for(int i=mid;i>=L;i--){
        while(j<=R&&pre[j]>=suf[i])j++;
        res+=1ll*suf[i]*(j-mid-1);
        res+=sum_pre[j];
    }
    return res;
}
int main(){
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    cout<<solve_max(1,n)-solve_min(1,n)<<endl;
}