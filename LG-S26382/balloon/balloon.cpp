#include <bits/stdc++.h>
#define pii pair<ll,ll>
using namespace std;
typedef long long ll;
const int N=5e3+10;
const ll maxn=1e15+10;
ll C[N][N],len[N];
void init(){
    memset(C,0,sizeof(C));
    C[0][0]=1;
    for(int i=1;i<N;i++){
        C[i][0]=1;
        for(int j=1;j<=i;j++){
            if(C[i-1][j]==-1) {C[i][j]=-1;break;}
            if(C[i-1][j]+C[i-1][j-1]>maxn) {C[i][j]=-1;break;}
            C[i][j]=C[i-1][j]+C[i-1][j-1];
        }
        len[i]=i;
        for(int j=1;j<=i;j++){
            if(C[i][j]==-1){
                len[i]=j-1;break;
            }
        }
    }
}
int main(){
    freopen("balloon.in","r",stdin);
    freopen("balloon.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t;cin>>t;init();
    while(t--){
        ll m;cin>>m;
        if(m==0||m==1) cout<<"0\n";
        else{
            priority_queue<pii,vector<pii>,greater<pii> > q;
            q.push({m,1});
            if(m!=2) q.push({m,m-1});
            for(ll i=N-1;i>=2;i--){
                int num=min(len[i],i/2);
                int pos=lower_bound(C[i]+1,C[i]+num+1,m)-C[i];
                if(pos<=num&&C[i][pos]==m){
                    if(pos==1) continue;
                    q.push({i,pos});
                    if(i!=pos*2) q.push({i,i-pos});
                }
            }
            cout<<q.size()<<"\n";
            while(!q.empty()){
                cout<<q.top().first<<" "<<q.top().second<<"\n";
                q.pop();
            }
        }
    }
    return 0;
}