#include<bits/stdc++.h>
#define ls(p) (p)<<1
#define rs(p) (p)<<1|1
using namespace std;
typedef long long ll;
const int N=1e5+10;
int n,m,a[N];
struct node{
    int num,tag1,tag2;
    int maxn[2],ls,llen,rs,rlen,flag;
    void init(int x){
        num=x;
        tag1=-1;tag2=0;flag=1;
        maxn[x]=1;maxn[x^1]=0;
        llen=rlen=1;ls=rs=x;
    }
}tree[N<<2];
struct res{
    int maxn[2],ls,llen,rs,rlen,flag;
    void init(node x){
        maxn[0]=x.maxn[0],maxn[1]=x.maxn[1];
        ls=x.ls,rs=x.rs;
        llen=x.llen,rlen=x.rlen,flag=x.flag;
    }
};
res merge(res x,res y){
    res ans;
    for(int bit=0;bit<2;bit++){
        ans.maxn[bit]=max(x.maxn[bit],y.maxn[bit]);
        if(x.rs==bit&&y.ls==bit)
            ans.maxn[bit]=max(ans.maxn[bit],x.rlen+y.llen);
    }
    int flag=0;
    if(x.flag&&y.flag){
        if(x.rs==y.ls) flag=1;
        else flag=0; 
    }
    else flag=0;
    ans.flag=flag;
    if(x.flag==1){
        if(x.ls==y.ls) ans.ls=x.ls,ans.llen=x.llen+y.llen;
        else ans.ls=x.ls,ans.llen=x.llen;
    }
    else ans.ls=x.ls,ans.llen=x.llen;
    if(y.flag==1){
        if(y.rs==x.rs) ans.rs=y.rs,ans.rlen=y.rlen+x.rlen;
        else ans.rs=y.rs,ans.rlen=y.rlen;
    }
    else ans.rs=y.rs,ans.rlen=y.rlen;
    return ans;
}
inline void push_up(int p){
    tree[p].num=tree[ls(p)].num+tree[rs(p)].num;
    for(int bit=0;bit<2;bit++){
        tree[p].maxn[bit]=max(tree[ls(p)].maxn[bit],tree[rs(p)].maxn[bit]);
        if(tree[ls(p)].rs==bit&&tree[rs(p)].ls==bit)
            tree[p].maxn[bit]=max(tree[p].maxn[bit],tree[ls(p)].rlen+tree[rs(p)].llen);
    }
    int flag=0;
    if(tree[ls(p)].flag&&tree[rs(p)].flag){
        if(tree[ls(p)].rs==tree[rs(p)].ls) flag=1;
        else flag=0; 
    }
    else flag=0;
    tree[p].flag=flag;
    if(tree[ls(p)].flag==1){
        if(tree[ls(p)].ls==tree[rs(p)].ls) tree[p].ls=tree[ls(p)].ls,tree[p].llen=tree[ls(p)].llen+tree[rs(p)].llen;
        else tree[p].ls=tree[ls(p)].ls,tree[p].llen=tree[ls(p)].llen;
    }
    else tree[p].ls=tree[ls(p)].ls,tree[p].llen=tree[ls(p)].llen;
    if(tree[rs(p)].flag==1){
        if(tree[rs(p)].rs==tree[ls(p)].rs) tree[p].rs=tree[rs(p)].rs,tree[p].rlen=tree[rs(p)].rlen+tree[ls(p)].rlen;
        else tree[p].rs=tree[rs(p)].rs,tree[p].rlen=tree[rs(p)].rlen;
    }
    else tree[p].rs=tree[rs(p)].rs,tree[p].rlen=tree[rs(p)].rlen;
}
inline void addtag1(int p,int pl,int pr,int num){
    tree[p].tag2=0;tree[p].tag1=num;
    tree[p].flag=1;
    tree[p].maxn[num]=pr-pl+1;tree[p].maxn[num^1]=0;
    tree[p].num=(pr-pl+1)*(num==1);
    tree[p].ls=tree[p].rs=num;
    tree[p].llen=tree[p].rlen=(pr-pl+1);
}
inline void addtag2(int p,int pl,int pr){
    swap(tree[p].maxn[0],tree[p].maxn[1]);
    if(tree[p].tag1!=-1){
        tree[p].tag1^=1;
        tree[p].ls^=1;tree[p].rs^=1;
    }
    else{
        tree[p].tag2^=1;
        tree[p].ls^=1;tree[p].rs^=1;
    }
    tree[p].num=(pr-pl+1)-tree[p].num;
}
inline void push_down(int p,int pl,int pr){
    if(tree[p].tag1==-1&&tree[p].tag2==0) return;
    if(tree[p].tag1!=-1){
        int mid=(pl+pr)>>1;
        addtag1(ls(p),pl,mid,tree[p].tag1);
        addtag1(rs(p),mid+1,pr,tree[p].tag1);
    }
    else{
        int mid=(pl+pr)>>1;
        addtag2(ls(p),pl,mid);
        addtag2(rs(p),mid+1,pr);
    }
    tree[p].tag1=-1;tree[p].tag2=0;
}
void build(int p,int pl,int pr){
    if(pl==pr){
        tree[p].init(a[pl]);
        return;
    }
    int mid=(pl+pr)>>1;
    build(ls(p),pl,mid);
    build(rs(p),mid+1,pr);
    push_up(p);
    tree[p].tag1=-1;tree[p].tag2=0;
}
void update1(int p,int pl,int pr,int L,int R,int num){
    if(L<=pl&&pr<=R){
        addtag1(p,pl,pr,num);
        return;
    }
    push_down(p,pl,pr);
    int mid=(pl+pr)>>1;
    if(mid>=L) update1(ls(p),pl,mid,L,R,num);
    if(mid<R) update1(rs(p),mid+1,pr,L,R,num);
    push_up(p);
}
void update2(int p,int pl,int pr,int L,int R){
    if(L<=pl&&pr<=R){
        addtag2(p,pl,pr);
        return;
    }
    push_down(p,pl,pr);
    int mid=(pl+pr)>>1;
    if(mid>=L) update2(ls(p),pl,mid,L,R);
    if(mid<R) update2(rs(p),mid+1,pr,L,R);
    push_up(p);
}
ll query1(int p,int pl,int pr,int L,int R){
    if(L<=pl&&pr<=R){
        return tree[p].num;
    }
    push_down(p,pl,pr);
    int mid=(pl+pr)>>1,ans=0;
    if(L<=mid) ans+=query1(ls(p),pl,mid,L,R);
    if(R>mid) ans+=query1(rs(p),mid+1,pr,L,R);
    return ans;
}
res query2(int p,int pl,int pr,int L,int R){
    res ans;
    if(L<=pl&&pr<=R){
        ans.init(tree[p]);
        return ans;
    }
    push_down(p,pl,pr);
    int mid=(pl+pr)>>1,mark=0;
    if(L<=mid) mark=1,ans=query2(ls(p),pl,mid,L,R);
    if(R>mid){
        if(mark==1) ans=merge(ans,query2(rs(p),mid+1,pr,L,R));
        else ans=query2(rs(p),mid+1,pr,L,R);
    }
    return ans;
}
int main(){
    //freopen(".in","r",stdin);
    //freopen(".out","r",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    build(1,1,n);
    for(int i=1;i<=m;i++){
        int opt,l,r;
        cin>>opt>>l>>r;l++,r++;
        if(opt<=1) update1(1,1,n,l,r,opt);
        else if(opt==2) update2(1,1,n,l,r);
        else if(opt==3) cout<<query1(1,1,n,l,r)<<"\n";
        else if(opt==4) cout<<query2(1,1,n,l,r).maxn[1]<<"\n";
    }
    return 0;
}
