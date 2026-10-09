#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
ll cnt,phi[N],vis[N],pri[N],sum[N];
void init()
{
    phi[1]=1;
    for(int i=2;i<N;i++){
        if(vis[i]==0){
            phi[i]=i-1;
            vis[i]=1;
            pri[++cnt]=i;
        }
        for(int j=1;j<=cnt;j++){
            if(i*pri[j]>N){
                break;
            }
            vis[i*pri[j]]=1;
            if(i%pri[j]==0){
                phi[i*pri[j]]=phi[i]*pri[j];
                break;
            }
            phi[i*pri[j]]=phi[i]*phi[pri[j]];
        }
    }
    sum[1]=1;
    for(int i=1;i<N;i++){
        sum[i]=sum[i-1]+phi[i];
    }
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,m;
	cin>>n>>m;
	ll ans=0;
	init();
	if(n>m) swap(n,m);
	for(int l=1,r=0;l<=n;l=r+1){
		r=min(n/(n/l),m/(m/l));
		ans+=(sum[r]-sum[l-1])*(n/l)*(m/l);
	}
	cout<<ans*2-n*m;
	return 0;
}

