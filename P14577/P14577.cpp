#include<bits/stdc++.h>
using namespace std;
template <typename T>
void read(T &x){
    x=0;int f=1;char ch=getchar();
    while(!isdigit(ch)){
        if(ch=='-') f*=-1;
        ch=getchar(); 
    }
    while(isdigit(ch)){
        x=(x<<3)+(x<<1)+(ch&15);
        ch=getchar();
    }
    x*=f;
}
typedef long long ll;
const int N=5e5+10,M=30;
int n,q,a[N],pre[30][N],sta[N][M],LOG2[N],now[N];
char s[N];
void init(){
    LOG2[0]=-1;
    for(int i=1;i<N;i++) LOG2[i]=LOG2[i>>1]+1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=25;j++) pre[j][i]=pre[j][i-1];
        pre[s[i]-'a'][i]=i;
    }
    for(int i=1;i<=n;i++) now[i]=now[i-1]^(sta[i][0]=(1<<(s[i]-'a')));
    for(int j=1;j<=19;j++){
        for(int i=1;i+(1<<j)-1<=n;i++) sta[i][j]=sta[i][j-1]|sta[i+(1<<(j-1))][j-1];
    }
}
ll query(ll l,ll r){
    if(l>r) return 0;
    int k=LOG2[r-l+1];
    return sta[l][k]|sta[r-(1<<k)+1][k];
}
int main(){
    read(n);scanf("%s",s+1);
    for(int i=1;i<=n;i++) read(a[i]);
    read(q);init();
    for(int i=1;i<=q;i++){
        int op,l,r;
        read(op);read(l);read(r);
        if(op==1) a[l]=r;
        else{
            ll ans=0;
            int g=now[l-1]^now[r];
            for(int x=g;x;x&=(x-1)){
                int c=__builtin_ctz(x),p=pre[c][r];
                if(p==0||p<l) continue;
                if(!((now[p-1]^now[l-1])&query(p+1,r))) ans+=a[p];
            }
            printf("%lld\n",ans);
        }
    }
    return 0;
}