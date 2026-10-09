#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e7+10;
ll cnt,vis[N],nxt[N];
typedef long long ll;
ll qp(ll k,ll n,ll INS)
{
	ll sum=1;
	while(n>0)
	{
		if(n&1)
		{
			sum=sum*k%INS;
		}
		k=k*k%INS;
		n>>=1;
	}
	return sum;
}
void init(){
	vis[1]=1;
	for(int i=2;i<N;i++){
		if(!vis[i]){
			for(int j=2;j*i<N;j++){
				vis[i*j]=1;
			}
		}
	}
	int flag=-1;
	for(int i=N-1;i>=1;i--){
		if(!vis[i]){
			flag=i;
		}
		nxt[i]=flag;
	}
} 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
	int n;
	cin>>n;
	ll lc=1,ans=0;
	for(int i=3;i<=n;i++){
		if(vis[i]==0){
			ans=ans+qp(lc,i-2,i)%i*(i-1)*1ll%i;
			lc=1;
		}
		else{
			lc=lc*i*1ll%nxt[i];
		}
	}
	cout<<ans;
	return 0;
}

