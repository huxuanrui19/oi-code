#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
ll n,x;
bool judge(ll cnt){
	for(ll i=1;i<=n;i=(i<<1)){
		if((i-cnt)%(x-1)==0&&i>=cnt) return 1; 
	}
	return 0;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	ll t;
	cin>>t;
	while(t--){
		cin>>n>>x;
		if(x==1){
			if((n&(n-1))==0) cout<<"Yes\n";
			else cout<<"No\n"; 
		}
		else{
			ll cnt=0,cur=n;
			while(cur){
				cnt+=cur%x;
				cur/=x;
			}
			if((cnt&(cnt-1))==0) cout<<"Yes\n";
			else if(judge(cnt)) cout<<"Yes\n";
			else cout<<"No\n";
		}
	}	
	return 0;
}

