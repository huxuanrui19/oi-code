#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
const ll inf=1e18,mod=1e9+7;
int n,m,L,V;
int d[N],a[N],v[N],p[N];
struct node{
    int l,r;
    bool operator <(const node &x) const{
        return l<x.l;
    }
}arr[N];
inline int getfloor(int a,int b){
    return a/b;
}
inline int getceil(int a,int b){
    return a/b+(a%b!=0);
}
int main(){
    //freopen("detect.in","r",stdin);
    //freopen("detect.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t;cin>>t;
    while(t--){
        cin>>n>>m>>L>>V;
        for(int i=1;i<=n;i++) cin>>d[i]>>v[i]>>a[i];
        for(int i=1;i<=m;i++) cin>>p[i];
        ll num=0;
        for(int i=1;i<=n;i++){
            if(a[i]==0){
                if(v[i]<=V) continue;
                if(d[i]<=p[m]){
                    arr[++num]={d[i],p[m]};
                }
            }
            else if(a[i]>0){
                if(v[i]>V){
                    if(d[i]<=p[m]) arr[++num]={d[i],p[m]};
                }else{
                    int l=getfloor(V*V-v[i]*v[i],2*a[i])+1;
                    if(l+d[i]<=p[m]) arr[++num]={l+d[i],p[m]};
                }
            }
            else if(a[i]<0){
                if(v[i]<=V) continue;
                int l=getceil(v[i]*v[i]-V*V,-2*a[i]);
                int pos=lower_bound(p+1,p+m+1,l+d[i])-p-1;
                if(p[pos]<d[i]) continue;
                else arr[++num]={d[i],p[pos]};
            }
        }
        cout<<num<<" ";
        sort(arr+1,arr+num+1);
        int lst=-1,res=0;
        for(int i=num;i>=1;i--){
            if(lst==-1){
                res++;
                lst=lower_bound(p+1,p+m+1,arr[i].l)-p;
            }else if(p[lst]<=arr[i].r) continue;
            else{
                res++;
                lst=lower_bound(p+1,p+m+1,arr[i].l)-p;
            }
        }
        cout<<m-res<<"\n";
    }
    return 0;
}