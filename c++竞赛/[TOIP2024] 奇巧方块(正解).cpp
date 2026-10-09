#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
ll pos,lid,rid,num,c[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	ll m,n,t,k,r;
	cin>>m>>n>>t>>k>>r;
	for(int i=1;i<=t;i++){
		cin>>c[i];
		if(c[i]<=k){
			num++;
			rid=i;
		}
	}
	ll ans=0,cnt=0,tot=(n-k+1)*(m-k+1);
	cnt=min(m,r+k-1)-max(1ll,r-k+1)-k+1+1;
	//cout<<cnt;
	pos=1,lid=1;
	c[t+1]=n+1;
	while(pos+k-1<=n){
		ll len1=c[lid]-pos+1;
		ll len2=c[rid+1]-pos-k+1;
		ll mv=min(len1,len2);
		pos+=mv;
		ans+=mv*cnt*(num%2);
		if(pos>c[lid]){
			num--;
			lid++;
		}
		if(rid+1<=t&&c[rid+1]<pos+k){
			num++;
			rid++;
		}
	}
	if(k%2==1){
		ans=tot-ans;
	}
	cout<<ans;
	return 0;
}
