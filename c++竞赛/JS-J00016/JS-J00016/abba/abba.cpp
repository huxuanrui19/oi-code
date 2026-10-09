#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
bool check(ll x){
	int a[20];
	memset(a,0,sizeof(a));
	ll cnt=0;
	while(x){
		a[++cnt]=x%10;
		x/=10;
	}
	for(int i=1;i*2<=cnt;i++){
		if(a[i]!=a[cnt-i+1]) return false;
	}
	return true;
}
int main(){
	freopen("abba.in","r",stdin);
	freopen("abba.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	ll n,ans=0;
	cin>>n;
	for(ll i=1;i*i*i<=n;i++){
		ll tmp=i*i*i; 
		if(check(tmp)) ans=max(ans,tmp);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

