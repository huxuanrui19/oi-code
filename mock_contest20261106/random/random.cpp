#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3e5+10;
const ll inf=1e18,mod=1e7+19;
ll n,k,q,a[N],inv[mod+10];
int vis[mod+10];
int main(){
    //freopen("D:\\oi-code\\mock_contest20261106\\random\\down\\ex_random2.in","r",stdin);
    //freopen("D:\\oi-code\\mock_contest20261106\\random\\down\\random.out","w",stdout);
    freopen("random.in","r",stdin);
    freopen("random.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int c;cin>>c;
    cin>>n>>q>>k;
    inv[1]=1;
    for(int i=2;i<mod;i++){
        inv[i]=-inv[mod%i]*(mod/i)%mod;
        inv[i]=(inv[i]%mod+mod)%mod;
    }
    for(int i=1;i<=n;i++) cin>>a[i];
    int cnt=0;
    while(q--){
        cnt++;
        int l,r;cin>>l>>r;
        if(r-l+1>=300&&k!=0) cout<<"1\n";
        else if(k==0) cout<<"0\n";
        else{
            int flag=0;
            for(int i=l;i<=r;i++){
                for(int j=i;j<=r;j++){
                    ll tar=k*inv[a[i]*a[j]%mod]%mod;
                    vis[a[i]*a[j]%mod]=cnt;
                    if(vis[tar]==cnt){flag=1;goto out;}
                }
            }
            out: ;
            if(flag) cout<<"1\n";
            else cout<<"0\n";
        }
    }
    return 0;
}