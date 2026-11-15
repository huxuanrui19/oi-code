#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10,M=50;
int n,s,a[N],qans[N];
struct node{
    int num,idx;
    bool operator <(const node &x) const{
        return num<x.num;
    }
}b[N];
int main(){
    //freopen("/Users/jerry/code_cpp_hxr/oi-code/P12763/ex/tom3ocen.in","r",stdin);
    //freopen(".out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>s;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) b[i]={a[i],i};
    sort(b+1,b+n+1);
    ll ans=0,lst=0;
    for(int i=1;i<=n;i++){
        if(lst==s-1) ans++,lst=0;
        lst=(lst+b[i].num+1)%s;
        qans[i]=b[i].idx;
    }
    ll cnt=0;
    while(cnt<M){
        cnt++;
        random_shuffle(b+1,b+n+1);
        ll cur=0,sum=0;
        for(int i=1;i<=n;i++){
            if(cur==s-1){
                sum++;
                if(sum>ans) goto out;
                cur=0;
            }
            cur=(cur+b[i].num+1)%s;
        }
        if(ans>sum){
            ans=sum;
            for(int i=1;i<=n;i++) qans[i]=b[i].idx;
        }
        out: ;
    }
    sort(b+1,b+n+1);
    int l=1,r=n;ll cur=0,sum=0;
    queue<int> q;
    while(l<=r){
        if(cur==s-1) cur=0,sum++;
        if((cur+b[r].num+1)%s==0){
            q.push(b[l].idx);cur=(cur+b[l].num+1)%s;
            if(l==r) break;
            if(cur==s-1) cur=0,sum++;
            q.push(b[r].idx);cur=(cur+b[r].num+1)%s;
            l++;r--;
        }
        else{
            q.push(b[r].idx);cur=(cur+b[r].num+1)%s;
            if(l==r) break;
            if(cur==s-1) cur=0,sum++;
            q.push(b[l].idx);cur=(cur+b[l].num+1)%s;
            l++;r--;
        }
        
    }
    if(sum<ans){
        ans=sum;
        for(int i=1;i<=n;i++) qans[i]=q.front(),q.pop();
    }
    while(!q.empty()) q.pop();
    sum=0,cur=0;
    set<pair<int,int> > st;
    for(int i=1;i<=n;i++){
        st.insert({(a[i]+1)%s,i});
    }
    queue<int> p;
    while(!st.empty()){
        if(cur==s-1) cur=0,sum++;
        int d=(s-1-cur+s)%s;
        auto it=prev(st.end());
        if(it->first==d&&st.size()>1&&prev(it)->first!=d) it--;
        cur=(cur+it->first)%s;
        p.push(it->second);
        st.erase(it);
    }
    if(sum<ans){
        ans=sum;
        for(int i=1;i<=n;i++) qans[i]=p.front(),p.pop();
    }
    cout<<ans<<"\n";
    for(int i=1;i<=n;i++) cout<<qans[i]<<" ";
    return 0;
}