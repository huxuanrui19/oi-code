#include<bits/stdc++.h>
using namespace std;
#define int long long
constexpr int maxn=1e3+10;
constexpr int maxm=1e4+10;
typedef struct node{
    int a,b;
    bool operator<(const node &other)const{
        return (this->a*this->b)<(other.a*other.b);
    }
}dc;
typedef struct bigint{
    int num[maxm],len;
    bigint(){
        memset(num,0,sizeof num);
        len=1;
    }
    bigint (const int &x){
        memset(num,0,sizeof num);
        len=1;
        int tmp=x;
        while(tmp){
            num[len]=tmp%10;
            tmp/=10;
            if(tmp){
                ++len;
            }
        }
    }
    bigint operator*(const int &x)const{
        bigint ret;
        ret.len=len+10;
        for(int i=1;i<=ret.len;++i){
            ret.num[i]+=num[i]*x;
            ret.num[i+1]+=ret.num[i]/10;
            ret.num[i]%=10;
        }
        while(ret.len>1&&!ret.num[ret.len]){
            --ret.len;
        }
        return ret;
    }
    bigint operator/(const int &x)const{
        bigint ret;
        int yu=0;
        ret.len=len;
        for(int i=len;i>=1;--i){
            ret.num[i]=(num[i]+yu*10)/x;
            yu=(num[i]+yu*10)%x;
        }
        while(ret.len>1&&!ret.num[ret.len]){
            --ret.len;
        }
        return ret;
    }
    bool operator<(const bigint &x)const{
        if(len<x.len){
            return true;
        }
        if(len>x.len){
            return false;
        }
        for(int i=len;i>=1;--i){
            if(num[i]<x.num[i]){
                return true;
            }
            if(num[i]>x.num[i]){
                return false;
            }
        }
        return false;
    }
    void prt(){
        for(int i=len;i>=1;--i){
            printf("%lld",num[i]);
        }
        putchar('\n');
    }
}bigint;
int n;
int a,b;
node t[maxn];
bigint _max(bigint &x,bigint &y){
    if(x<y){
        return y;
    }
    return x;
}
signed main(){
    scanf("%lld",&n);
    scanf("%lld%lld",&a,&b);
    bigint lst=a;
    for(int i=1;i<=n;++i){
        scanf("%lld%lld",&t[i].a,&t[i].b);
    }
    sort(t+1,t+n+1);
    bigint ans=0;
    for(int i=1;i<=n;++i){
        bigint tmp=lst/t[i].b;
        ans=_max(ans,tmp);
        lst=lst*t[i].a;
    }
    ans.prt();
    return 0;
}