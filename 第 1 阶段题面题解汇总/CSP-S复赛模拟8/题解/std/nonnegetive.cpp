#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=101000;
int a[N],n;
ll nd[4*N];
void upd(int p) {
    nd[p]=max(nd[p+p],nd[p+p+1]);
}
void build(int p,int l,int r) {
    if (l==r) {
        nd[p]=a[l];
    } else {
        int md=(l+r)>>1;
        build(p+p,l,md);
        build(p+p+1,md+1,r);
        upd(p);
    }
}
int query(int p,int l,int r,ll v) {
    if (l==r) return l;
    else {
        int md=(l+r)>>1;
        if (nd[p+p]>=v) return query(p+p,l,md,v);
        else return query(p+p+1,md+1,r,v);
    }
}
void change(int p,int l,int r,int x,ll v) {
    if (l==r) nd[p]=v;
    else {
        int md=(l+r)>>1;
        if (x<=md) change(p+p,l,md,x,v);
        else change(p+p+1,md+1,r,x,v);
        upd(p);
    }
}

int main() {
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",a+i);
    build(1,1,n);
    ll s=0;
    vector<int> ans;
    for (int i=1;i<=n;i++) {
        if (nd[1]<-s) {
            puts("-1");
            return 0;
        } else {
            int id=query(1,1,n,-s);
            ans.push_back(id);
            s+=a[id];
            change(1,1,n,id,-(1ll<<60));
        }
    }
    for (int i=0;i<n;i++) printf("%d%c",ans[i]," \n"[i==n-1]);
}
