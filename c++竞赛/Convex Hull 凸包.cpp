#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+10;
ll tao[N],vis[N],pri[N],sum1[N],sum2[N];
void init()
{
    tao[1]=1;
    int cnt=0;
    for(int i=2;i<N;i++){
        if(vis[i]==0){
            tao[i]=2;
            vis[i]=1;
            pri[++cnt]=i;
        }
        for(int j=1;j<=cnt;j++){
            if(i*pri[j]>N){
                break;
            }
            vis[i*pri[j]]=1;
            if(i%pri[j]==0){
            	int tmp=i,e=0;
            	while(tmp%pri[j]==0){
            		tmp/=pri[j];
            		e++;
				}
				tao[i*pri[j]]=tao[i]/(e+1)*(e+2);
                break;
            }
            tao[i*pri[j]]=tao[i]*tao[pri[j]];
        }
    }
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,m,p;
	cin>>n>>m>>p;
	if(n>m) swap(n,m);
	ll ans=0;
	init();
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m/i;j++){
			if(i<=n&&j<=n/i) sum1[i]=(sum1[i]+tao[j*i])%p;
			sum2[i]=(sum2[i]+tao[j*i])%p;
		}
	}
	for(int i=1;i<=n;i++){
		ans=(ans+(sum1[i]*sum2[i])%p)%p;
	}
	cout<<ans;
	return 0;
}

