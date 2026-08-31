#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
const ll mod=1e9+7;
ll pw[N],c[10];
ll cal(string s){
	ll q=0,ans=0,n=s.size(),sum1=0;
	memset(c,0,sizeof(c));
	for(int i=0;i<n;i++){
		ll up=s[i]-'0';
		ll m=n-i-1;
		ans=(ans+q*up*pw[m])%mod;
		
		if(m>=1) ans+=((sum1*up%mod+up*(up-1)/2%mod)%mod*m%mod*pw[m-1]%mod);
		ans%=mod;
		if(m>=2) ans+=(m*(m-1)/2)%mod*up%mod*45%mod*pw[m-2]%mod;
		ans%=mod;
		
		ll sum2=0;
		for(ll d=0;d<=9;d++) sum2+=c[d]*min(d,up);
		ans=(ans+sum2%mod*pw[m]%mod)%mod; 
		
		for(int j=up+1;j<=9;j++) q=(q+c[j])%mod;
		sum1+=up;
		c[up]++;
	}
	return (ans+q);
}
int main() {
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	pw[0]=1;for(int i=1;i<N;i++) pw[i]=pw[i-1]*10%mod;
	while(t--){
		string l,r;
		cin>>l>>r;
		for(int i=l.size()-1;i>=0;i--){
			if(l[i]=='0') l[i]='9';
			else{
				l[i]--;break;
			}
		}
		cout<<(cal(r)-cal(l)+mod)%mod<<"\n";
	}
	return 0;
}
