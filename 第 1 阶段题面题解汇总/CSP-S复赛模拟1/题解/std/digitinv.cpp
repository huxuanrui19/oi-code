#include<bits/stdc++.h>
#define ll long long
const int p=1e9+7;
using namespace std;

inline int mo(int x) {
    return x>=p?x-p:x;
}

const int N=5e5+5;
int f[N][10],ans,n,a[N],b[120],mi[N],g[N];
ll c[20];

void dgs(int t) {
    if(t>n) {
        g[t]=1;
        return;
    }
    g[t]=(ll)a[t]*mi[n-t]%p;
    dgs(t+1);
    g[t]=mo(g[t]+g[t+1]);
}
ll dfs(int t) {
    if(t>n) return 0;
    ll sum=0;
    for(int i=a[t]+1;i<=9;i++) {
        sum=(sum+(ll)b[i]*g[t+1])%p;
    }
//    printf("%d %d\n",pre,t);
    int w=0;
    for(int k=0;k<=9;k++) {
        if(n-t>0) w=mo(w+(ll)b[k]*mi[n-t-1]%p*k*(n-t)%p);
    }
    for(int k=9;k>=0;k--) {
        c[k]=(c[k+1]+(ll)b[k]*mi[n-t])%p;
    }
    for(int j=0;j<a[t];j++) {
        sum=mo(sum+f[n-t+1][j]);
        sum=mo(sum+c[j+1]);
        sum=mo(sum+w);
    }
    b[a[t]]++;
    sum=mo(sum+dfs(t+1));
    return sum;
} 

int main() {
    mi[0]=1;
    for(int i=1;i<=500000;i++) {
        mi[i]=(ll)mi[i-1]*10%p;
    } 
    for(int i=2;i<=500000;i++) {
        int s=0; int t=(ll)mi[i-2]*(i-1)%p;
        for(int j=0;j<=9;j++) {
            s=mo(s+f[i-1][j]);
        }
        for(int j=0;j<=9;j++) {
            f[i][j]=s;
            s=mo(s+t);
        }
    }
    int T; scanf("%d",&T);
    while(T--) { 
        ans=0;
        n=0; char ch=getchar();
        while(ch<'0'||ch>'9') ch=getchar();
        while(ch>='0'&&ch<='9') {
            a[++n]=ch-'0'; ch=getchar();
        }
        for(int i=n;i;i--) {
            if(a[i]) {
                a[i]--; break;
            } else a[i]=9;
        }
        for(int i=0;i<=9;i++) b[i]=0; 
        if(a[1]==0) dgs(2),ans=mo(p-dfs(2));
            else dgs(1),ans=mo(p-dfs(1));
        n=0; 
        while(ch<'0'||ch>'9') ch=getchar();
        while(ch>='0'&&ch<='9') {
            a[++n]=ch-'0'; ch=getchar();
        }
        for(int i=0;i<=9;i++) b[i]=0;
        dgs(1),ans=mo(ans+dfs(1));
        printf("%d\n",ans);
    }
    return 0;
}
