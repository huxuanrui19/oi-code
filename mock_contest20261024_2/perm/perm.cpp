#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
const int N=1e3+10;
const ll maxn=1e18,mod=998244353;
int n,r[N];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int c,t;cin>>c>>t;
    while(t--){
        cin>>n;for(int i=1;i<=n;i++) cin>>r[i];
        if(n<=10){
            int q[11];int ans=0;
            for(int i=1;i<=n;i++) q[i]=i;
            do{
                int p[11];
                for(int i=1;i<=10;i++) p[i]=i;
                for(int i=1;i<=n;i++){
                    swap(p[q[i]],p[q[i]%n+1]);
                }
                int flag=1;
                for(int i=1;i<=n;i++){
                    if(p[i]!=r[i]) flag=0;
                }
                ans+=flag;
            }while(next_permutation(q+1,q+n+1));
            cout<<ans<<"\n";
        }
        else{
            int flag=0;
            for(int i=1;i<=n;i++){
                if(i==r[i]) flag=i;
            }
            if(flag){
                vector<int> v1,v2;
                v1.resize(n+1);v2.resize(n+1);
                for(int i=1;i<=n;i++){
                    v1[i]=v2[i]=i;
                }
                int i=flag;
                int mark=0;
                while(mark==0||flag!=i){
                    mark=1;
                    swap(v1[i],v1[i%n+1]);
                    i=i%n+1;
                }
                mark=0;i=flag;
                while(mark==0||flag!=i){
                    mark=1;
                    swap(v2[i],v2[(i-1)%n+(i==1)*n]);
                    i--;if(i==0) i+=n;
                }
                ll ans1=1,ans2=1;
                for(int i=1;i<=n;i++){
                    if(v1[i]!=r[i]) ans1=0;
                    if(v2[i]!=r[i]) ans2=0;
                }
                cout<<max(ans1,ans2)<<"\n";
            }
            else cout<<"0\n";
        }
    }
    return 0;
}
