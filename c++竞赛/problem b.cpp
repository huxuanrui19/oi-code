#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e4+10;
ll cnt,mu[N],vis[N],pri[N],sum[N];
void init()
{
    mu[1]=1;
    for(int i=2;i<N;i++){
        if(vis[i]==0){
            mu[i]=-1;
            vis[i]=1;
            pri[++cnt]=i;
        }
        for(int j=1;j<=cnt;j++){
            if(i*pri[j]>=N){
                break;
            }
            vis[i*pri[j]]=1;
            if(i%pri[j]==0){
                mu[i*pri[j]]=0;
                break;
            }
            mu[i*pri[j]]=mu[i]*mu[pri[j]];
        }
    }
    sum[1]=mu[1];
    for(int i=2;i<N;i++){
    	sum[i]=sum[i-1]+mu[i];
	}
}
ll kkk(ll a,ll b,ll d){
	a/=d;
	b/=d;
	ll ans=0;
	if(a<b) swap(a,b);
	for(ll l=1,r=0;l<=b;l=r+1){
		r=min(a/(a/l),b/(b/l));
		ans+=(sum[r]-sum[l-1])*(long long)(a/l)*(b/l);
	}
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
	int t;
	cin>>t;
	while(t--){
		ll a,b,c,d,k;
		cin>>a>>b>>c>>d>>k;
		cout<<kkk(a-1,c-1,k)-kkk(a-1,d,k)-kkk(b,c-1,k)+kkk(b,d,k)<<endl;
	}
	return 0;
}

