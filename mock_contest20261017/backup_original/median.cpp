#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
const ll inf=1e18,mod=1e9+7;
int n,a[N],pre[N],suf[N];
int main(){
    freopen("median.in","r",stdin);
    freopen("median.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    pre[1]=a[1];suf[n]=a[n];
    priority_queue<int,vector<int>,less<int> > p;
    priority_queue<int,vector<int>,greater<int> > q;
    p.push(a[1]);
    for(int i=3;i<=n;i+=2){
        int b=a[i-1],c=a[i];
        if(b>p.top()) q.push(b);
        else p.push(b);
        if(c>p.top()) q.push(c);
        else p.push(c);
        if(p.size()>q.size()+1){
            while(p.size()>q.size()+1){
                q.push(p.top());
                p.pop();
            }
        }
        else if(p.size()<q.size()+1){
            while(p.size()<q.size()+1){
                p.push(q.top());
                q.pop();
            }
        }
        pre[i]=p.top();
    }
    while(!p.empty()) p.pop();
    while(!q.empty()) q.pop();
    p.push(a[n]);
    for(int i=n-2;i>=1;i-=2){
        int b=a[i],c=a[i+1];
        if(b>p.top()) q.push(b);
        else p.push(b);
        if(c>p.top()) q.push(c);
        else p.push(c);
        if(p.size()>q.size()+1){
            while(p.size()>q.size()+1){
                q.push(p.top());
                p.pop();
            }
        }
        else if(p.size()<q.size()+1){
            while(p.size()<q.size()+1){
                p.push(q.top());
                q.pop();
            }
        }
        suf[i]=p.top();
    }
    bool flag=0;
    for(int i=1;i<=n;i+=2){
        if(pre[i]==suf[i+1]) flag=1;
    }
    if(flag==1) cout<<"Yes";
    else cout<<"No";
    return 0;
}