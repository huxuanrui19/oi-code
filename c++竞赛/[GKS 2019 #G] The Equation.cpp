#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e3+10,M=51;
const ll inf=1e18;
ll n,m,a[N],s[N][M],cnt[M],num0[M],num1[M],pos[M];
int main() {
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int t,idx=0;cin>>t;
	while(t--){
		cin>>n>>m;idx++;
		cout<<"Case #"<<idx<<": "; 
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++){
			for(ll j=0;j<M;j++){
				if((a[i]&(1ll<<j))) s[i][j]=1;
				else s[i][j]=0;
			}
		}
		__int128 sum=0;
		for(ll i=0;i<M;i++){
			num0[i]=num1[i]=0;
			for(int j=1;j<=n;j++){
				if(s[j][i]==1) num1[i]++;
				else num0[i]++;
			}
			if(num1[i]>=num0[i]){
				pos[i]=1;
				sum+=(__int128)(num0[i])*(1ll<<i);
			}
			else{
				pos[i]=0;
				sum+=(__int128)(num1[i])*(1ll<<i);
			}
		}
		for(ll j=M-1;j>=0;j--){
			if(num1[j]<num0[j]&&sum+((__int128)(num0[j]-num1[j]))*(1ll<<j)<=m){
				pos[j]=1;
				sum+=((__int128)(num0[j]-num1[j]))*(1ll<<j);
			}
		}
		if(sum>m) cout<<"-1";
		else{
			ll ans=0;
			for(ll j=0;j<M;j++) ans+=pos[j]*(1ll<<j);
			cout<<ans;
		}
		cout<<"\n";
	}
	return 0;
}
