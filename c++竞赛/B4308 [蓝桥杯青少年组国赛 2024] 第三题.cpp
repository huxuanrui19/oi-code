#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e7+10;
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
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
	int n,m;
	cin>>m>>n;
	cout<<sum[n]-sum[m-1];
	return 0;
}

